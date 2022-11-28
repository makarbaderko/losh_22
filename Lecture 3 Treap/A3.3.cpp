#include<iostream>
#include<vector>
#include<string>
#include<random>
using namespace std;

struct Node {
    int key;
    int pr;
    int left, right;
    int sz;
    int min;
    int max;
};

Node nodes[1000000];
int nodesNumber = 0;

bool exists (int root, int x){
    int v = root;
    while (v != -1){
        if (nodes[v].key == x){
            return true;
        }
        if (nodes[v].key > x){
            v = nodes[v].left;
        }
        else{
            v = nodes[v].right;
        }
    }
    return false;
}
int getSz (int v){return (v >= 0)?nodes[v].sz: 0;}
int makeNewNode (int x) {
    Node newNode;
    newNode.key = x;
    newNode.pr = rand();
    newNode.left = -1;
    newNode.right = -1;
    newNode.sz = 1;
    newNode.min = x;
    newNode.max = -1;
    nodes[nodesNumber] = newNode;
    return nodesNumber++;
}
void recalculate(int v){
    nodes[v].sz = getSz(nodes[v].left) + 1 + getSz(nodes[v].right);
    nodes[v].min = (nodes[v].left < 0)?nodes[v].key:nodes[nodes[v].left].min;
    nodes[v].max = (nodes[v].right < 0)?nodes[v].key:nodes[nodes[v].right].max;
}
pair<int, int> SPLIT (int root, int x){
    if (root == -1){
        return make_pair(-1, -1);
    }
    if (nodes[root].key <= x){
        pair<int, int> p = SPLIT(nodes[root].right, x);
        nodes[root].right = p.first;
        recalculate(root);
        return make_pair(root, p.second);
    }
    else {
        pair<int, int> p = SPLIT(nodes[root].left, x);
        nodes[root].left = p.second;
        recalculate(root);
        return make_pair(p.first, root);
    }
}
int MERGE (int root1, int root2){
    if (root2 == -1){
        return root1;
    }
    if (root1 == -1){
        return root2;
    }
    if (nodes[root1].pr < nodes[root2].pr){
        nodes[root1].right = MERGE(nodes[root1].right, root2);
        recalculate(root1);
        return root1;
    }
    else {
        nodes[root2].left = MERGE(root1, nodes[root2].left);
        recalculate(root2);
        return root2;
    }
}
int INSERT (int root, int x){
    int newNode = makeNewNode(x);
    pair <int, int> p = SPLIT(root, x);
    return MERGE(p.first, MERGE(newNode, p.second));
}

int ERASE (int root, int x){
    pair<int, int> p = SPLIT(root, x);
    pair<int, int> pp = SPLIT(p.first, x - 1);
    return MERGE(pp.first, p.second);
}
int kth (int root, int b){
    if (getSz(nodes[root].left) >= b){
        return kth(nodes[root].left, b);
    }
    if (getSz(nodes[root].left) == b - 1){
        return nodes[root].key;
    }
    else {
        return kth(nodes[root].right, b - getSz(nodes[root].left) - 1);
    }
}

int main(){
    string s;
    int x;
    int root = -1;
    int res = 0;
    while (cin >> s >> x){
        if (s == "insert"){
            root = INSERT(root, x);
            res++;
        }
        else if (s == "delete"){
            root = ERASE(root, x);
            res--;
        }
        else if (s == "exists"){
            if (exists(root, x)){
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        else if (s == "next"){
            int d = nodes[SPLIT(root, x).second].min;
            if (d == 0){
                cout << "none" << endl;
            }
            else {
                cout << d << endl;
            }
        }
        else if (s == "prev"){
            int d = nodes[SPLIT(root, x + 1).first].max;
            if (d > 0){
                cout << d << endl;
            }
            else {
                cout << "none" << endl;
            }
        }
        else {
            if (x <= res){
                cout << kth(root, x) << '\n';
            }
            else {
                cout << "none\n";
            }
        }
    }
}
