#include <iostream>
#include <vector>
#include<string>

using namespace std;

vector<int>pairInL;
vector<int>used;
vector<vector<int> > gr;

bool dfs(int v){
    if(used[v]){
        return false;
    };
    used[v] = true;
    for(int i = 0; i<gr[v].size(); i++){
        int unt = gr[v][i];
        if(pairInL[unt] == -1 or dfs(pairInL[unt])){
            pairInL[unt] = v;
            return true;
        }
    }
    return false;
}


int main(){
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int m, n;
        cin >> m >> n;
        vector<vector<int> > gr(m);
        for (int i = 0; i < m; i++) {
            vector<int> vec;
            while(true){
                int v;
                cin >> v;
                if(v == 0) {
                    break;
                } 
                vec.push_back(v);
            }
            gr[i] = vec;
        }

        f
        
    }
}