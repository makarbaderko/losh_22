#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> >gr;
vector<int> par;
vector<int>used;
vector<int>pairInL;

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

int main(){
    int m, n;
    cin >> m >> n;
    gr.resize(m);
    for (int i = 0; i < m; i++) {
        vector<int> vec;
        int k = 0;
        cin >> k;
        for (int j = 0; k < n; j++) {
            int v;
            cin >> v;
            vec.push_back(v);
        }
        gr[i] = vec;
    }
    par.resize(m);
    for (int i = 0; i < m; i++) {
        int k = 0;
        cin >> k;
        par.push_back(k);
    }
    
}