#include<iostream>

using namespace std;

struct Node{
    int right,left;
    int value;
    int sz,pr;
    int min;
};
Node nodes[200000];
int nodesNumber = 0;




int getMin (int v) {
  return (v >= 0) ? nodes[v].min: (int)1e9 + 1;
}
/*
int getMin(int v){
  return (v >= 0 ? nodes[v].min : 0);
}
*/
int getRand(){
  return (rand() << 15) + rand();
}


int buildNewNode(int value){
  Node newNode;
  newNode.left = -1;
  newNode.right = -1;
  newNode.pr = getRand();
  newNode.value = value;
  newNode.sz = 1;
  newNode.min  = value;
  nodes[nodesNumber] = newNode;
  return nodesNumber++;
}

int &left(int v){
  return left(v);
}

int &right(int v){
  return right(v);
}

int &sz(int v){
  return nodes[v].sz;
}

int getSz(int v){
  return (v >= 0 ? sz(v) : 0);
}



void recalculate(int v){
    nodes[v].sz = getSz(left(v)) + 1 + getSz(right(v));
    nodes[v].min = min(nodes[v].value, min(getMin(left(v)), getMin(right(v))));
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
    pair<int,int> p = splitBySize(root,pos);
    int newn = buildNewNode(x);
    return merge(merge(p.first,newn),p.second);
}

int main(){
    int root = -1;
    int n, l, r;
    char req;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> req;
        if (req == '+') {
            cin >> l >> r;
            root = insert(root, l, r);
        } else {
            cin >> l >> r;
            pair<int, int>p = splitBySize(root, l - 1);
            pair<int, int>pp = splitBySize(p.second, r - l + 1);
            cout << nodes[pp.first].min << endl;
            root = merge(p.first,merge(pp.first, pp.second));
        }
    }
}
