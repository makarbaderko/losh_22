#include<string>
#include<random>
using namespace std;


struct Node {
    int key;
    int pr;
    int left, right;
    int sum;
};

vector<Node>nodes;
int nodesNumber = 0;

int getRand(){
  return (rand() << 15) + rand();
}
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
int getSz (int v){return (v >= 0) ? nodes[v].sz: 0;}
int makeNewNode(int x) {
    Node newNode;
    newNode.key = x;
    newNode.pr = getRand();
    newNode.left = -1;
    newNode.right = -1;
    newNode.sum = x;
    nodes.push_back(newNode);
    return nodes.size() - 1;
}
void recalculate(int v){
    nodes[v].sum = getSum(nodes[v].left) + nodes[v].key + getSum(nodes[v].right);
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

int getSum (int v){return (v >= 0) ? nodes[v].sum: 0;}

int sum(int root, int l, int r) {
  
}

int main(){
    string req;
    int root = -1;
    int res = 0;
    char prev = '-';
    long long pr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
      cin >> req;
      if(req == '+' and (i == 0 or prev == '+')){
        int x = 0;
        cin >> x;
        insert(root, x);
    } else if (req == '+' and prev == '?'){
      int x = 0;
      cin >> x;
      insert(root, (pr + x) % 1e9);
    } else {
      int l, r;
      cin >> l >> r;
      pr = sum(root, l, r);
      cout << pr << '\n';
    }
    prev = req;
  }
}
