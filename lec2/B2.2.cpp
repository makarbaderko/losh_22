#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>>t;
int n;

int sum(int x, int y,int z){
    int res= 0;
    for (int i = x;i >= 0;i = (i & (i + 1)) - 1)
        for (int j = y;j >= 0;j = (j & (j + 1)) - 1)
            for (int k = z;k >= 0;k = (k & (k + 1)) - 1)
                res += t[i][j][k];
    return res;
}
void inc(int x,int y,int z,int delta) {
    for (int i = x; i < n; i = (i | (i + 1)))
        for (int j = y; j < n; j = (j | (j + 1)))
            for (int l = z; l < n; l = (l | (l + 1)))
                t[i][j][l] += delta;
}
int main() {
    int k,x,y,z,x2,y2,z2;
    cin>>n;
    t=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,0)));
    while (true){
        cin>>k;
        if (k==3){
            return 0;
        }else if (k==2){
            cin>>x>>y>>z>>x2>>y2>>z2;
            x--;y--;z--;
            int a = sum(x2,y2,z2);
            int b = sum(x2,y,z2);
            int c = sum(x2,y2,z);
            int d = sum(x,y2,z2);
            int e = sum(x2,y,z);
            int f = sum(x,y,z2);
            int g = sum(x,y2,z);
            int h = sum(x,y,z);
            cout<<sum(x2,y2,z2)-sum(x2,y,z2)-sum(x2,y2,z)-sum(x,y2,z2)+sum(x2,y,z)+sum(x,y,z2)+sum(x,y2,z)-sum(x,y,z)<<endl;
        }else{
            int delta;
            cin>>x>>y>>z>>delta;
            inc(x,y,z,delta);
        }
    }
}