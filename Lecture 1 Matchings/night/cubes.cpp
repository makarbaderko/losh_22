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
    pairInL.assign(name.size(), -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 6; k++) {
                if (name[i] == cubes[j][k]) {
                    gr[j].push_back(i);
                }
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
    if (ans == name.length()) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(pairInL[i] != -1){
                cout << pairInL[i] + 1 << " ";
            }
        }
    } else {
        cout << "NO" << endl;
    }
}