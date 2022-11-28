#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, const vector<vector<int> >& edges, vector<bool>& used) {
	used[v] = 1;
	for (auto to : edges[v]) {
		if (!used[to]) dfs(to, edges, used);
	}
}

vector<bool> mvp(int m, const vector<vector<int> >& edges, const vector<int>& unused) {
	vector<bool> used(edges.size(), 0);
	for (auto v : unused) {
		if (!used[v]) dfs(v, edges, used);
	}
	for (int i = 0; i < m; ++i) {
		used[i] = !used[i];
	}
	return used;
}

int main() {
	int n, m;
	cin >> m >> n;
	vector<vector<int> > graph(n + m);
	for (int i = 0; i < m; ++i) {
		int deg;
		cin >> deg;
		graph[i].resize(deg);
		for (int j = 0; j < deg; ++j) {
			int to;
			cin >> to;
			graph[i][j] = m + to - 1;
		}
	}
	vector<int> unused;
	for (int i = 0; i < m; ++i) {
		int match;
		cin >> match;
		if (match != 0) {
			graph[m + match - 1].push_back(i);
		}
		else {
			unused.push_back(i);
		}
	}
	vector<bool> cover = mvp(m, graph, unused);
	vector<int> cover1, cover2;
	for (int i = 0; i < m; ++i) {
		if (cover[i]) cover1.push_back(i + 1);
	}
	for (int i = 0; i < n; ++i) {
		if (cover[m + i]) cover2.push_back(i + 1);
	}
	cout << cover1.size() + cover2.size() << endl;
	cout << cover1.size() << ' ';
	for (int i = 0; i < cover1.size(); ++i) {
		cout << cover1[i] << ' ';
	}
	cout << endl << cover2.size() << ' ';
	for (int i = 0; i < cover2.size(); ++i) {
		cout << cover2[i] << ' ';
	}
}
