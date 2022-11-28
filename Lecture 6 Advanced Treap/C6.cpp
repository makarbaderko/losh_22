#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    int left;
    int right;
    int value;
    int size;
    int pr;
    int min;
};
Node Nodes[(long long)2e5];
int NodesNumber=0;

int getMin (int v) {
  return (v >= 0) ? Nodes[v].min: (int)1e9 + 1;
}
int getrand(){
  return (random() << 15) + rand();
}
int getSz (int v){
  return (v >= 0) ? Nodes[v].size: 0;
}
int buildNewNode(int value){
    Node newNode;
    newNode.right = -1;
    newNode.left = -1;
    newNode.value = value;
    newNode.size = 1;
    newNode.pr = getrand();
    newNode.min = value;
    Nodes[NodesNumber] = newNode;
    return NodesNumber++;
}

int &left(int v){
  return Nodes[v].left;
}

int &right(int v){
  return Nodes[v].right;
}


void recalculate(int v){
    Nodes[v].size = getSz(Nodes[v].left) + 1 + getSz(Nodes[v].right);
    Nodes[v].min = min(Nodes[v].value, min(getMin(Nodes[v].left), getMin(Nodes[v].right)));
}

pair<int,int> splitBySize(int root,int szleft) {
    if (!szleft) {
        return make_pair(-1, root);
    }
    if (getSz(Nodes[root].left) >= szleft) {
        pair<int, int>p = splitBySize(Nodes[root].left,szleft);
        Nodes[root].left = p.second;
        recalculate(root);
        return make_pair(p.first, root);
    } else {
        pair<int, int>p = splitBySize(Nodes[root].right, szleft - getSz(Nodes[root].left) - 1);
        Nodes[root].right= p.first;
        recalculate(root);
        return make_pair(root, p.second);
    }
}
int merge(int root1,int root2){
    if (root1 < 0){
        return root2;
    }
    if (root2 < 0){
        return root1;
    }
    if (Nodes[root1].pr < Nodes[root2].pr){
        Nodes[root1].right = merge(Nodes[root1].right, root2);
        recalculate(root1);
        return root1;
    }
    else {
        Nodes[root2].left = merge(root1, Nodes[root2].left);
        recalculate(root2);
        return root2;
    }
}
int insert(int root,int pos,int x){
    pair<int,int> p = splitBySize(root,pos);
    int newn = buildNewNode(x);
    return merge(merge(p.first,newn),p.second);
}

struct Triple {
  int left, middle, right;
}

Triple getSubsegment(int root, int l, int r) {
  pair<int, int>p = splitBySize(root, l - 1);
  pair<int, int>p2 =  splitBySize(p.second, r - l + 1);
  return Triple{p.first, p2.first, p2.second};
}

int mergeTriple(Triple t){
  return merge(merge(t.left, t.middle), t.right);
}

int erase(int root, int pos) {
  Triple t = getSubsegment(root, pos, pos);
  return merge(t.left, t.right);
}

int getSumOnSubsegment(int &root, int l, int r){
  Triple t = getSubsegment(root, l, r);
  int ans = getSum(t.middle);
  root = mergeTriple(t);
  return ans;
}




int main(){
    int root = -1;
    int n, l, r;
    cin >> n;
    char req;
    for (int i = 0; i < n; ++i) {
        cin >> req;
        if (req == '+') {
            cin >> l >> r;
            root = insert(root, l, r);
        } else {
            cin >> l >> r;
            pair<int,int>p = splitBySize(root, l - 1);
            pair<int,int>pp = splitBySize(p.second, r - l + 1);
            cout << Nodes[pp.first].min << endl;
            root = merge(p.first,merge(pp.first, pp.second));
        }
    }
}
