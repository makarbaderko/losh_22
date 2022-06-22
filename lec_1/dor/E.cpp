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
    for(int i = 0; i<gr[v].size(); i++){
        int unt = gr[v][i];
        if(pairInL[unt] == -1 or dfs(pairInL[unt])){
            pairInL[unt] = v;
            return true;
        }
    }
    return false;
}


int main() {
    int n, k;
    cin >> n >> k;
    gr.resize(n);
    for (int i = 0; i < (k*n); i++){
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
    }
    for(int i = 0;  i< n; i++){
        used.assign(n, false);
        dfs(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(pairInL[i] != -1) {
            ans++;
        }
    }
    cout << ans << endl;
    for(int i = 0; i<n; i++){
        if(pairInL[i] != -1){
        cout<< pairInL[i]+1 << " " << i+1 << endl;
    }
    }
}