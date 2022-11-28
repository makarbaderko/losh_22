#include<iostream>

using namespace std;

long long maxN=2e5;
struct Node{
    int right;
    int left;
    int value;
    int sz;
    int pr;
    int min;
};
Node nodes[maxN];
int nodesNumber=0;

int getMin (int v) {
  return (v >= 0)? nodes[v].min: (int)1e9 + 1;
}
int GetRand(){
  return randomik()%(int)2e5 ;
}
int getSz (int v){return (v >= 0)?nodes[v].sz: 0;}
int buildNewNode(int value){
    nodes[nodesNumber]=Node{-1,-1,value,1,GetRand(),value};
    return nodesNumber++;
}void recalculate(int v){
    nodes[v].sz= getSz(nodes[v].left)+1+getSz(nodes[v].right);
    nodes[v].min =min(nodes[v].value,min(getMin(nodes[v].left), getMin(nodes[v].right)));
}
pair<int,int> splitBySize(int root,int szLeft) {
    if (!szLeft) {
        return make_pair(-1, root);
    }
    if (getSz(nodes[root].left) >= szLeft) {
        pair<int, int> p = splitBySize(nodes[root].left, szLeft);
        nodes[root].left = p.second;
        recalculate(root);
        return make_pair(p.first, root);
    } else {
        pair<int, int> p = splitBySize(nodes[root].right, szLeft - getSz(nodes[root].left) - 1);
        nodes[root].right = p.first;
        recalculate(root);
        return make_pair(root, p.second);
    }
}
int merge(int root1,int root2){
    if (root2 < 0){
        return root1;
    }if (root1 < 0){
        return root2;
    }if (nodes[root1].pr < nodes[root2].pr){
        nodes[root1].right = merge(nodes[root1].right, root2);
        recalculate(root1);
        return root1;
    }else {
        nodes[root2].left = merge(root1, nodes[root2].left);
        recalculate(root2);
        return root2;
    }
}int insert(int root,int pos,int x){
    pair<int,int> p = splitBySize(root,pos);
    int newn = buildNewNode(x);
    return merge(merge(p.first,newn),p.second);
}
int main(){
    int n,nn,x,root = -1,l,r;
    pair<int,int> p,p2;
    cin >> n;
    char s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == '+') {
            cin >> nn >> x;
            root = insert(root, nn, x);
        } else {
            cin >> l >> r;
            p = splitBySize(root, l - 1);
            p2 = splitBySize(p.second, r - l + 1);
            cout << nodes[p2.first].min << '\n';
            root = merge(p.first,merge(p2.first, p2.second));
        }
    }
}
