#include <iostream>
#include <vector>

using namespace std;


bool dfs(int v){
    if(used[v]){
        return false
    };
    used[v] = true;
    for(int i = 0; i<g[v].size(); i++){
        int unt = g[v][i];
        if(pairInL[unt] == -1 or dfs(pairIntL[unt])){
            pairInL[unt] = v;
            return true;
        }
    }
    return false;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int> >g(n);
    vector<int>pairInL;
    pairInL.assign(k, -1);
    vector<char>used;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        while(v != 0){
            g[i].push_back(v - 1);
            cin >> v;
        }
    }
    for(int i = 0;  i< n; i++){
        used.assign(n, false);
        dfs(i);
    }
    int ans = 0;
    for(int i = 0; i < k; i++){
        if(pairInL[i] != -1) {
            ans++;
        }
    }
    cout << ans << endl;
    for(int i = 0; i<k; i++){
        if(pairInL[i] != -1){
        cout<< pairInL[i]+1 << " " << i+1 << endl;
    }
    }
    return 0;
}