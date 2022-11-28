#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> >gr;
vector<int>par;
vector<int>pairInL;
vector<int>used;
vector<vector<int> >field;

bool dfs(int v){
    if(used[v]){
        return false;
    };
    used[v] = true;
    for(int i = 0; i < gr[v].size(); i++){
        int unt = gr[v][i];
        if(pairInL[unt] == -1 or dfs(pairInL[unt])){
            pairInL[unt] = v;
            return true;
        }
    }
    return false;
}


int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    field.resize(n);
    for (int i = 0; i < n; i++){
        vector<int> vec;
        for(int j = 0; j < m; j++){
            char v;
            int vi;
            cin >> v;
            if(v == '.') {
                vi = 1;
            } else {
                vi = 0;
            }
            vec.push_back(vi);
        }
        field[i] = vec;
    }
    gr.resize(n);
    
}