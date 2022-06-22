#include <vector>

using namespace std;

struct Node {
    int key;
    int pr; //(if tree was realized with prioritization)
    int left, right; // -1 если соответствующего реенка нет
};
Node nodes[100500];
int nodesNumber;

bool exists(int root, int x) {
    int v = root;
    while (v != -1) {
        /*Node & nd = nodes[v];
        if (nd.key == x) {
            return true;
        }
        if (nd.key > x) {
            v = nd.left;
        } else {
            v = nd.right;
        }
        */
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
    nodes[nodesNumber++] = Node{x, -1, -1}; /*  с приоритетами - nodes[nodesNumber++] = Node{x, getRand(), -1, -1};
    return nodesNumber++;
}


pair<int, bool> insert(int root, int x) {
    if (root < 0) {
        int v = makeNewNode(x);
        return make_pair(v, true);
    }
    int v = 0;
    while (true) {
        Node& ndv = nodes[v];
        if(ndv.key == x) {
            return make_pair(v, false);
        }
        if(ndv.key > x) {
            if(ndv.left == -1) {
                ndv.left = makeNewNode(x);
                return {ndv.left, true};
            } else {
                v = ndv.left;
            }
        }
    }
}

//Prioritized tree
//SPLIT (root, x) -> (root1, root2);
//MERGE (root1, root2) -> root
//Ве функции будут реализовываться за счет split и merge
//Пишем insert без учитывания того, что элемент уже есть (перед этим вызвали exist и получили false) 
/* возвращаем корень */ int insert(int root, int x) {
    int newNode = makeNewNode(x);

}