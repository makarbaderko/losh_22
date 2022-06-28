#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int res = 0;
    long long d[1 << n];
    for (int i = 0; i < 1 << n; i++){
        d[i] = 1;
    }
    for (int i = 0; i < x; ++i){
        int m;
        cin >> m;
        vector<int> b;
        for (int j = 0; j < m; ++j){
            int h;
            cin >> h;
            b.push_back(h);
        }
        for (int mask = 0; mask < 1 << n; ++mask){
            int sdvig = 1;
            for (int j = 0; j < n; ++j){
                int row = 0;
                if ((mask & (1 << j))){
                    for (int k = 0; k < m; k++){
                        if (b[k] == j + 1){
                            row = 1;
                        }
                    }
                    sdvig = sdvig & row;
                }
            }
            if (sdvig && d[mask]){
                d[mask] = 0;
                res++;
            }
        }
    }
    for (int i = 0; i < y; ++i){
        int m;
        cin >> m;
        vector<long long> a;
        for (int j = 0; j < m; ++j){
            int h;
            cin >> h;
            a.push_back(h);
        }
        for (int mask = 0; mask < 1 << n; ++mask){
            int sdvig = 1;
            for (int j = 0; j < n; ++j){
                int row = 0;
                if ((mask & (1 << j))){
                    for (int k = 0; k < m; k++){
                        if (a[k] == j + 1){
                            row = 1;
                        }
                    }
                    sdvig = sdvig & row;
                }
            }
            if (sdvig && !d[mask]){
                d[mask] = 1;
                res--;
            }
        }
    }
    cout << res << endl;
    return 0;
}
