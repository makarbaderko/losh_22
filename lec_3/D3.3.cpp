#include <vector>
#include<iostream>
#include<string>
#include <algorithm>
#include<set>
#include<random>
using namespace std;

struct Node {
    int key;
    int pr; //(if tree was realized with prioritization)
    int left, right; // -1 если соответствующего реенка нет
    int sz; // сколько вершин находится в поддереве этой вершины
    int min;
    int max;
    int height;
};

Node nodes[1000000];
int nodesNumber = 0;


bool exists(int root, int x) {
    int v = root;
    while (v != -1) {
        if (nodes[v].key == x){
            return true;
        }
        if (nodes[v].key > x) {
            //Едем налево
            v = nodes[v].left;
        } else {
            v = nodes[v].right;
        }
    }
    return false;
}

int getSz(int v) {return (v >= 0) ? nodes[v].sz : 0;}

/int getRand() {
  return (rand() << 15) + rand();
}

int makeNewNode(int x) {
    Node newNode;
    newNode.key = x;
    newNode.pr = getRand();
    newNode.left = -1;
    newNode.right = -1;
    newNode.sz = 1;
    newNode.min = x;
    nodes[nodesNumber] = newNode;
    return nodesNumber++;
}




void recalculate(int v) {
    nodes[v].sz = getSz(nodes[v].left) + 1 + getSz(nodes[v].right);
    nodes[v].min = (nodes[v].left < 0) ? nodes[v].key : nodes[nodes[v].left].min;
}




pair<int, int> SPLIT(int root, int x) {
    if (root == -1) {
        return make_pair(-1, -1);
    } if (nodes[root].key <= x) {
        pair<int, int>p = SPLIT(nodes[root].right, x);
        nodes[root].right = p.first;
        recalculate(root);
        return make_pair(root, p.second);
    } else {
        //Самостоятельное написание ++
        pair<int, int>p = SPLIT(nodes[root].left , x);
        nodes[root].left = p.second;
        recalculate(root);
        return make_pair(p.first, root);
    }
}


int MERGE(int root1, int root2) {
    if(root2 == -1) {
        return root1;
    } if(root1 == -1) {
        return root2;
    } if (nodes[root1].pr < nodes[root2].pr) {
        //Root1 будет новым корнем, Т.к. его приоритет меньше чем приоритет корня root2
        nodes[root1].right = MERGE(nodes[root1].right, root2);
        recalculate(root1);
        return root1;
    } else {
        //Самостоятельное написание ++
        nodes[root2].left = MERGE(root1, nodes[root2].left);
        recalculate(root2);
        return root2;
    }
}



int insert(int root, int x) {
    int newNode = makeNewNode(x);
    pair<int, int>p = SPLIT(root, x);
    return MERGE(p.first, MERGE(newNode, p.second));
}

int erase(int root, int x) {
    pair<int, int> p = SPLIT(root, x);
    pair<int, int> pp = SPLIT(p.first, x-1);
    return MERGE(pp.first, p.second);
}


int main(){
  string s;
  int x;
  int root = -1;
  while(cin >> s >> x) {
    if (s == "insert"){
      root = insert(root, x);
    } else if (s == "delete"){
      root = erase(root, x);
    } else {
      if (exists(root, x)) {
        cout << "true" << "\n";
      } else {
        cout << "false" << "\n";
      }
    }
  }
}
