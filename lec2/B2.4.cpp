#include <iostream>
#include <vector>


using namespace std;
#define int long long
vector<vector<vector<int> > >t;
int n;
int sum(int x, int y,int z){
    int result = 0;
    for (int i = x;i >= 0;i = (i & (i + 1)) - 1)
        for (int j = y;j >= 0;j = (j & (j + 1)) - 1)
            for (int l = z;l >= 0;l = (l & (l + 1)) - 1)
                result += t[i][j][l];
    return result;
}
void add(int x,int y,int z,int delta) {
    for (int i = x; i < n; i = (i | (i + 1)))
        for (int j = y; j < n; j = (j | (j + 1)))
            for (int k = z; k < n; k = (k | (k + 1)))
                t[i][j][k] +=delta;
}
int main() {
    int k,x1,y1,z1,x2,y2,z2;
    cin>>n;
    t=vector<vector<vector<int> > >(n,vector<vector<int> >(n,vector<int>(n,0)));
    while (true){
        cin>>k;
        if (k==3){
            return 0;
        }else if (k==2){
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            x1--;y1--;z1--;
            cout<<sum(x2,y2,z2)-sum(x2,y1,z2)-sum(x2,y2,z1)-sum(x1,y2,z2)+sum(x2,y1,z1)+sum(x1,y1,z2)+sum(x1,y2,z1)-sum(x1,y1,z1)<<endl;
        }else{
            int delta;
            cin>>x1>>y1>>z1>>delta;
            add(x1,y1,z1,delta);
        }
    }
    return 0;
}
