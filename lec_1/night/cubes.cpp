#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<int>pairInL;
vector<int>used;
vector<vector<int> > gr;

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
    int n;
    cin >> n;
    string name;
    cin >> name;
    gr.resize(n);
    vector<string>cubes;
    for (int i = 0; i < n; i++) {
        string cube;
        cin >> cube;
        cubes.push_back(cube);
    }
    pairInL.assign(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strstr(name.c_str(), cubes[i].c_str())) {
                gr[i].push_back(j);
            }
        }
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
    if (ans == n) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(pairInL[i] != -1){
                cout<< pairInL[i]+1 << " " << i+1 << endl;
            }
        }
    } else {
        cout << "NO" << endl;
    }

}