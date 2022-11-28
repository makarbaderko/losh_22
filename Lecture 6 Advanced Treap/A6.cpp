#include<iostream>
#include<algorithm>

using namespace std;


struct Node {
  int left, right;
  int value;
  int sum;
  int pr;
  int sz;
};

Node nodes[100000];
int nodesNumber = 0;

int getRand(){
  return (rand() << 15) + rand();
}

struct Triple {
  int left, middle, right;
};


int &left(int v){
  return nodes[v].left;
}

int &right(int v){
  return nodes[v].right;
}
int &pr(int v){
  return nodes[v].pr;
}


int &sum(int v){
  return nodes[v].sum;
}

int &sz(int v){
  return nodes[v].sz;
}

int &value(int v){
  return nodes[v].value;
}

int getSum(int v){
  return (v >= 0 ? sum(v) : 0);
}

int getSz(int v){
  return (v >= 0 ? sz(v) : 0);
}

void recalculate(int v) {
  sum(v) = getSum(left(v)) + value(v) + getSum(right(v));
  sz(v) = getSz(left(v)) + 1 + getSz(right(v));
}




int buildNewNode(int value){
  Node newNode;
  newNode.left = -1;
  newNode.right = -1;
  newNode.value = value;
  newNode.pr = getRand();
  newNode.sz = 1;
  newNode.sum = value;
  nodes[nodesNumber] = newNode;
  return nodesNumber++;
}



pair<int, int> splitBySize(int root, int szLeft) {
  // Разбить дерево на 2 поддерева так,
  //чтобы размер левого поддерева был рвен szLeft
  if (!szLeft) {
    return make_pair(-1, root);
  } if (getSz(left(root)) >= szLeft){
    pair<int, int>p = splitBySize(left(root), szLeft);
    left(root) = p.second;
    recalculate(root);
    return make_pair(p.first, root);
  } else {
    //Самостоятельное написание ++
    pair<int, int>p = splitBySize(right(root), szLeft - getSz(nodes[root].left) - 1);
    right(root) = p.first;
    recalculate(root);
    return make_pair(root, p.second);
  }
}


int merge(int root1, int root2) {
  if (root1 < 0){
    return root2;
  } if (root2 < 0) {
    return root1;
  } if (pr(root1) < pr(root2)) {
    right(root1) = merge(right(root1), root2);
    recalculate(root1);
    return root1;
  } else {
    //Самостоятельное написание ++
    left(root2) = merge(root1, left(root2));
    recalculate(root2);
    return root2;
  }
}

//Перая задача - вызвать mergeTriple (поменять left и middle)

void showTree(int root){
  if (root < 0) {
    return;
  }
  showTree(left(root));
  cout << value(root) + 1 << " ";
  showTree(right(root));
}


int main(){
  int n, m;
  int root = -1;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    root = merge(root, buildNewNode(i));
  } for (int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    pair<int, int>p = splitBySize(root, l - 1);
    pair<int, int>pp = splitBySize(p.second, r - l + 1);
    root = merge(merge(pp.first, p.first), pp.second);
  }
  showTree(root);
  return 0;
}
