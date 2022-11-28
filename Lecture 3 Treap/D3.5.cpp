#include<iostream>
#include<vector>
#include<string>
#include<random>

using namespace std;

struct Node {
    int key;
    int pr;
    int sum;
    int left, right;
};

vector<Node> nodes;
int nodesNumber = 0;

int getRand() {
    return (rand() << 15) + rand();
}
int getSum(int v){
    if (v != -1){
        return nodes[v].sum;
    }
    return 0;
}
int makeNewNode (int x) {
    nodes.push_back(Node{x, getRand(), x, -1, -1});
    return nodes.size() - 1;
}
void recalculate(int v){
    nodes[v].sum = getSum(nodes[v].left) + nodes[v].key  +  getSum(nodes[v].right);
}
bool EXISTS (int root, int x){
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
pair<int, int> SPLIT (int root, int x){
    if (root == -1){
        return make_pair(-1, -1);
    }
    if (nodes[root].key <= x){
        pair<int, int> p = SPLIT(nodes[root].right, x);
        nodes[root].right = p.first;
        recalculate(root);
        return {root, p.second};
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


signed main(){
    string req;
    int x;
    int root = -1;
    int res = 0;
    long long n;
    long long pr = -1;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> req;
        if (req == "+"){
            cin >> x;
            if (pr == -1){
                if (!EXISTS(root, x)){
                    root = INSERT(root, x);
                }
            }
            else {
                if (!EXISTS(root, (x + pr) % 1000000000))
                    root = INSERT(root, (x + pr) % 1000000000);
            }
            pr = -1;
        }
        else {
            int l, r;
            cin >> l >> r;
            pair<int, int> g = SPLIT(root, l - 1);
            pair<int, int> h = SPLIT(g.second, r);
            pr = getSum(h.first);
            cout << pr << '\n';
            root = MERGE(g.first, MERGE(h.first, h.second));
        }
    }
}
