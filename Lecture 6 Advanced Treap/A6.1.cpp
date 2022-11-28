#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<random>
using namespace std;

struct Node {
    int left, right;
    int value, sum;
    int sz, pr;
};

Node nodes[100000];
int nodesNumber = 0;
struct Triple{
    int left,middle,right;
};

int getSz (int v){return (v >= 0)?nodes[v].sz: 0;}
int getSum(int v){
    return(v >= 0)?nodes[v].sum:0;
}
int getRand(){
    return (rand() << 15) + rand();
}
int buildnewnode(int value){
    nodes[nodesNumber] = Node {-1, -1, value, value, 1, getRand()};
    return nodesNumber++;
}
void recalculate(int v){
    nodes[v].sum = getSum(nodes[v].left) + nodes[v].value + getSum(nodes[v].right);
    nodes[v].sz = getSz(nodes[v].left) + 1 + getSz(nodes[v].right);
}
pair<int,int> splitbysize(int root,int szleft) {
    if (!szleft) {
        return make_pair(-1, root);
    }
    if (getSz(nodes[root].left) >= szleft) {
        pair<int, int> p = splitbysize(nodes[root].left, szleft);
        nodes[root].left = p.second;
        recalculate(root);
        return make_pair(p.first, root);
    }
    else {
        pair<int, int> p = splitbysize(nodes[root].right, szleft - getSz(nodes[root].left) - 1);
        nodes[root].right = p.first;
        recalculate(root);
        return make_pair(root, p.second);
    }
}
int merge(int root1, int root2){
    if (root2 < 0){
        return root1;
    }
    if (root1 < 0){
        return root2;
    }
    if (nodes[root1].pr < nodes[root2].pr){
        nodes[root1].right = merge(nodes[root1].right, root2);
        recalculate(root1);
        return root1;
    }
    else {
        nodes[root2].left = merge(root1, nodes[root2].left);
        recalculate(root2);
        return root2;
    }
}
int insert(int root,int pos,int x){
    pair<int,int> p = splitbysize(root, pos-1);
    int newn = buildnewnode(x);
    return merge(merge(p.first, newn), p.second);
}
void print(int t){
    if (t == -1){
        return;
    }
    print(nodes[t].left);
    cout << nodes[t].value + 1 << ' ';
    print(nodes[t].right);
}
int main(){
    int n, m, root = -1;
    cin >> n >> m;
    int l, r;
    for (int i = 0; i < n; i++){
        root = merge(root, buildnewnode(i));
    }
    for (int i = 0; i < m; i++){
        cin >> l >> r;
        pair<int, int> p = splitbysize(root, l - 1);
        pair<int, int> h = splitbysize(p.second, r - l + 1);
        root = merge(merge(h.first, p.first), h.second);
    }
    print(root);
}