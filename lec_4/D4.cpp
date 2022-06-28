#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int ans;
    int d[1 << n];
    for (int i = 0; i < 1 << n; i++){
        d[i] = 1;
    }
    for (int i = 0; i < x; ++i){
        int m;
        cin >> m;
        vector<int> vec;
        for (int j = 0; j < m; ++j){
            int h;
            cin >> h;
            vec.push_back(h);
        }
        for (int mask = 0; mask < 1 << n; ++mask){
            int row = 1;
            for (int j = 0; j < n; ++j){
                int sdvig = 0;
                if ((mask & (1 << j))){
                    for (int k = 0; k < m; l++){
                        if (vec[k] == j + 1){
                            sdvig = 1;
                        }
                    }
                    row = row & sdvig;
                }
            }
            if (row && d[mask]){
                d[mask] = 0;
                ans++;
            }
        }
    }
    for (int i = 0; i < y; ++i){
        int m;
        cin >> m;
        vector<int> a;
        for (int j = 0; j < m; ++j){
            int h;
            cin >> h;
            a.push_back(h);
        }
        for (int mask = 0; mask < 1 << n; ++mask){
            int row = 1;
            for (int j = 0; j < n; ++j){
                int sdvig = 0;
                if ((mask & (1 << j))){
                    for (int l = 0; l < m; l++){
                        if (a[l] == j + 1){
                            sdvig = 1;
                        }
                    }
                    row = row & sdvig;
                }
            }
            if (row && !d[mask]){
                d[mask] = 1;
                ans -=1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
