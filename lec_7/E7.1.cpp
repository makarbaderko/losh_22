#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tree {
    Tree() {
        nodes.emplace_back();
    }
    struct Node {
        int next[128];
        vector<int> isTerminal;
        int sLink;
        int ssLink;
    };
    vector <Node> nodes;
    int size = 0;
    void add(const string& s) {
        int current = 0;
        for (char i : s) {
            int nextCharInAlphabet = i - 'a';
            if (!nodes[current].next[nextCharInAlphabet]) {
                nodes.emplace_back();
                nodes[current].next[nextCharInAlphabet] = (int) nodes.size() - 1;
            }
            current = nodes[current].next[nextCharInAlphabet];
        }
        nodes[current].isTerminal.push_back(size++);
    }
    void buildTree() {
        queue<int> qu;
        qu.push(0);
        while (!qu.empty()) {
            int current = qu.front();
            qu.pop();

            for (int i = 0; i < 26; ++i) {
                if (!nodes[current].next[i]) {
                    nodes[current].next[i] = nodes[nodes[current].sLink].next[i];
                } else {
                    int next = nodes[current].next[i];
                    if (current) {
                        nodes[next].sLink = nodes[nodes[current].sLink].next[i];
                        nodes[next].ssLink = !nodes[nodes[next].sLink].isTerminal.empty() ? nodes[next].sLink : nodes[nodes[next].sLink].ssLink;
                    }
                    qu.push(next);
                }
            }
        }
    }

    vector<bool> findOccurrent(string& t) {
        vector<bool> occurrent(size);
        vector<bool> found(nodes.size());

        int current = 0;
        for (char i : t) {
            current = nodes[current].next[i - 'a'];
            int tmp = current;
            while (!found[tmp]) {
                if (!nodes[tmp].isTerminal.empty()) {
                    for (auto&& ends : nodes[tmp].isTerminal)
                        occurrent[ends] = true;
                }
                found[tmp] = true;
                tmp = nodes[tmp].ssLink;
            }
        }
        return occurrent;
    }
};

Tree a;

int main() {
    int n;
    string s, ss;
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ss;
        a.add(ss);
    }
    a.buildTree();
    vector<bool> ans = a.findOccurrent(s);
    for (auto res : ans) {
        if (res){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}
