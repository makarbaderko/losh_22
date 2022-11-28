#include <vector>

using namespace std;

struct Node {
    int key;
    int pr; //(if tree was realized with prioritization)
    int left, right; // -1 если соответствующего реенка нет
    int sz; // сколько вершин находится в поддереве этой вершины
    int min; // минимум поддерева этйо вершины
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
     /* без всего nodes[nodesNumber++] = Node{x, -1, -1}; /*  с приоритетами - nodes[nodesNumber++] = Node{x, getRand(), -1, -1}; */
    nodes[nodesNumber++] = Node{x, getRand(), -1, -1, 1, x};
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
    pair<int, int>p = SPLIT(root, x);
    return MERGE(p.first, MERGE(newNode, p.second));
}
//посплитим деревл на 3 эелмента (=x, <x, >x)
// <x = pp.first; x = pp.second >x p.second
int erase(int root, int x) {
    pair<int, int>p = SPLIT(root, x);
    pair<int, int>pp = MERGE(p.first, x-1);
    return MERGE(p.first, p.second);
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
//Задача поиска k-го элемента
//давайте хранить в каждой вершине сколько вершин хранится в её поддеревьях (sz)

void recalculate(int v) {
    nodes[v].sz = getSz(nodes[v].left) + 1 + getSz(nodes[v].right);
    nodes[v].min = (nodes[v].left < 0) ? nodes[v].key : nodes[nodes[v].left].min;
}

int getSz(int v) {return (v >= 0) ? nodes[v].sz : 0;}

//Найти k-ый элемент дерева, если гарантируется, что он там есть.
int findKth(int root, int b){
    if(getSz(nodes[root].left) >= k) {
        return findKth(nodes[root].left, b);
    } if (getSz(nodes[root].left) == k - 1) {
        return nodes[root].key;
    } return findKth(nodes[root].right, k - getSize(nodes[root].left) - 1);
}