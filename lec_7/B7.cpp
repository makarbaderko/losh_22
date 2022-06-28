#include <iostream>
#include<vector>

using namespace std;

string s;
int m;
int h [10000000];
int p [1000000];
long long mod = 1e9+3;
int osn = 179;
int get(int l, int r){
    return int(h[r+1]-h[l]*p[r-l+1]);
}

signed main(){
    cin >> s >> m;
    h[0] = 0;
    p[0] = 1;
    for(int i = 0; i < s.size(); i++){
        h[i+1] = h[i] * osn + s[i];
        p[i+1] = p[i] * osn;
    }
    for(int i = 0; i<m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(get(a - 1, b - 1) == get(c - 1, d - 1)) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
    }
    return 0;
}
