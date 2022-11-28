#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> >gr;
vector<int>par;
vector<int>pairInL;
vector<int>used;

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
    int m, n;
    cin >> m >> n;
    gr.resize(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> vec;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            vec.push_back(v);
        }
        gr[i] = vec;
    }
    par.resize(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        par[i] = k;
    }
    //L- не входит в dfs
    for (int i = 0; i < m; i++) {
        if (par[i] == 0) {
            used.assign(n, false);
            dfs(i);
        }
    }
    
}