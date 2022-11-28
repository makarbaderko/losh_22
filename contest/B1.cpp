#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll n, ll x){
    ll n_no = n;
    ll pw = 0;
    while(n_no != 0){
        n_no /= 10;
        pw++;
    }

}
signed main(){
    vector<ll>a;
    a.push_back(1);
    a.push_back(4);
    a.push_back(9);
    a.push_back(49);
    a.push_back(64);
    a.push_back(81);
    string n;
    cin >> n;
    ll cnt = 0;
    for(ll i = 0; i<n.size(); i+=2){
        for(auto i:a){
            if(check(n, x)){
                cnt++;
            }
        }
    }
    return 0;
}
