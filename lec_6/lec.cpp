struct Node {
  int left, right;
  int value;
  int pr;
  int sz;
  int sum;
  bool isAssigned;
  int assigned;
  int add;
}

Node nodes[MAXN];
int nodesNumber = 0;

int buildNewNode(int value){
  Node newNode;
  newNode.left = -1;
  newNode.right = -1;
  newNode.pr = getRand();
  newNode.sz = 1;
  newNode.sum = value;
  newNode.isAssigned = false;
  newNode.assigned = 0;
  newNode.add = 0;
  nodes[nodesNumber] = newNode;
  return nodesNumber++;
}

int &left(int v){
  return nodes[v].left;
}

int &right(int v){
  return nodes[v].right;
}

int &sum(int v){
  return nodes[v].sum;
}

int &sz(int v){
  return nodes[v].sz;
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

pair<int, int> splitBySize(int root, int szLeft) {
  // Разбить дерево на 2 поддерева так,
  //чтобы размер левого поддерева был рвен szLeft
  if (szLeft == 0) {
    return make_pair(-1; root);
  } if (getSz(left(root)) >= szLeft){
    push(root);
    pair<int, int>p = splitBySize(left(root), szLeft);
    left(root) = p.second();
    recalculate(root);
    return make_pair(p.first, root);
  } else {
    //Самостоятельное написание
  }
}

int merge(int root1, int root2) {
  if (root1 < 0){
    return root2
  } if (root2 < 0) {
    return root1
  } if (pr(root1) < pr(root2)) {
    push(root1);
    right(root1) = merge(right(root1), root2);
    recalculate(root1);
    return root1;
  } else {
    //Самостоятельное написание
  }
}

int insert(int root, int pos, int x){
    pair<int, int>p = splitBySize(root, pos - 1);
    int newV = buildNewNode(x);
    return merge(merge(p.first, newv), p.second);
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

int assign(int root, int pos, int x){
  Triple t = getSubsegment(root, pos, pos);
  t.middle = buildNewNode(x);
  return mergeTriple(t);
}
//Перая задача - вызвать mergeTriple (поменять left и middle)

void assignOnSubtree(int root, int x){
  if (root < 0) return;
  nodes[root].isAssigned = true;
  nodes[root].assigned = x;
  nodes[root].value = x;
  nodes[root].sum = x * sz(root);
}

void push(int root){
  if (isAssigned(root)){
    assignOnSubtree(left(root), assigned(root));
    assignOnSubtree(right(root), assigned(root));
    isAssigned(root) = false;
  }
}

void assignOnSubsegment(int root, int l, int r, int x) {
  Triple t = getSubsegment(root, l, r);
  assignOnSubtree(t.middle, x);
  root = mergeTriple(t);
}
