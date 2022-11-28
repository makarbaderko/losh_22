#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<int> >gr;
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
int main(){

    int n, k;
    cin >> n >> k;
    pairInL.assign(k, -1);
    gr.resize(n);
    for(int i = 0; i < (k * n); i++){
        int v;
        cin >> v;
        while(v != 0){
            gr[i].push_back(v - 1);
            cin >> v;
        }
    }
    for(int i = 0;  i< n; i++){
        used.assign(n, false);
        dfs(i);
    }
    cout << "dfs finished" << endl;
    int ans = 0;
    for(int i = 0; i < k; i++){
        if(pairInL[i] != -1) {
            ans++;
        }
    }
    cout << "ans++ finished" << endl;
    for(int i = 0; i<k; i++){
        if(pairInL[i] != -1){
        cout<< pairInL[i]+1 << " " << i+1 << endl;
    }
    }
    cout << "ans++ finished" << endl;
    return 0;
}