#include <vector>

using namespace std;

struct Node {
    int key;
    int pr; //(if tree was realized with prioritization)
    int left, right; // -1 если соответствующего реенка нет
    int sz; // сколько вершин находится в поддереве этой вершины
    int min; // минимум поддерева этйо вершины
};

Node nodes[];
int nodesNumber;

bool exists(int root, int x) {
    int v = root;
    while (v != -1) {
        if (nodes[v].key == x){
            return true;
        }
        if (nodes[v].key > x) {
            //Едем налево
            v = nodes[v].left();
        } else {
            v = nodes[v].right();
        }
    }
    return false;
}

int makeNewNode(int x) {
    nodes[nodesNumber++] = Node{x, getRand(), -1, -1, 1, x};
    return nodesNumber++;
}

pair<int, int> SPLIT(int root, int x) {
    if (root == -1) {
        return {-1; -1};
    } if (nodes[root].key < x) {
        pair<int, int>p = SPLIT(nodes[root].right, x);
        nodes[root].right = p.first;
        recalculate(root);
        return {root, p.second};
    } else {
        //Самостоятельное написание
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
        recalculate(root1)
        return root1
    } else {
        //Самостоятельное написание
    }
}



int insert(int root, int x) {
    int newNode = makeNewNode(x);
    pair<int, int>p = SPLIT(root, x);
    return MERGE(p.first, MERGE(newNode, p.second));
}

int erase(int root, int x) {
    pair<int, int>p = SPLIT(root, x);
    pair<int, int>pp = MERGE(p.first, x-1);
    return MERGE(p.first, p.second);
}


void recalculate(int v) {
    nodes[v].sz = getSz(nodes[v].left) + 1 + getSz(nodes[v].right);
    nodes[v].min = (nodes[v].left < 0) ? nodes[v].key : nodes[nodes[v].left].min;
}

int getSz(int v) {return (v >= 0) ? nodes[v].sz : 0;}
