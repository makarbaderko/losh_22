#include <iostream>
#include <vector>

using namespace std;
#define ll long long
vector<vector<vector<ll > > >t;
int n;
ll sum(ll x, ll y,ll z){
    int result = 0;
    for (int i = x;i >= 0;i = (i & (i + 1)) - 1)
        for (int j = y;j >= 0;j = (j & (j + 1)) - 1)
            for (int l = z;l >= 0;l = (l & (l + 1)) - 1)
                result += t[i][j][l];
    return result;
}
void inc(ll x,ll y,ll z,ll delta) {
    for (int i = x; i < n; i = (i | (i + 1)))
        for (int j = y; j < n; j = (j | (j + 1)))
            for (int l = z; l < n; l = (l | (l + 1)))
                t[i][j][l] +=delta;
}
int main() {
    int k,x1,y1,z1,x2,y2,z2;
    cin>>n;
    t=vector<vector<vector<ll > > >(n,vector<vector<ll> >(n,vector<ll>(n,0)));
    while (true){
        cin>>k;
        if (k==3){
            return 0;
        }else if (k==2){
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            x1--;y1--;z1--;
            cout<<sum(x2,y2,z2)-sum(x2,y1,z2)-sum(x2,y2,z1)-sum(x1,y2,z2)+sum(x2,y1,z1)+sum(x1,y1,z2)+sum(x1,y2,z1)-sum(x1,y1,z1)<<endl;
        }else{
            ll delta;
            cin>>x1>>y1>>z1>>delta;
            inc(x1,y1,z1,delta);
        }
    }
