#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, a, b;
    cin >> m >> n >> a >> b;
    vector<vector<int> > matrix(n);
    for (int i = 0; i < n; i++) {
        vector<int> vec;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            vec.push_back(v);
        }
        matrix[i] = vec;
    }
    
}