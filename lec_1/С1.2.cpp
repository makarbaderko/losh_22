#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[1000];
vector<int> mt;
vector<char> used(1000);
vector<pair<int, int>> edge_num;

bool kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int v, u;
        cin >> v >> u;
        while (v != 0 && u != 0) {
            g[i].push_back(v - 1);
            g[i + 1].push_back(u - 1);
            break;
        }
    }
    mt.assign(n, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        kuhn(v);
    }
    for (size_t i = 0; i < m; ++i) {
        if (mt[i] != -1)
            edge_num.emplace_back(make_pair(mt[i] + 1, i + 1));
    }
    cout << edge_num.size() << '\n';
    for (auto &edge : edge_num) {
        cout << edge.first << ' ' << edge.second << '\n';
    }
    return 0;
}
