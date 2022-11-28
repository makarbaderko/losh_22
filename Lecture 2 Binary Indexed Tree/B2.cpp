#include <iostream>
#include <vector>
#include <string>

using namespace std;


int n;
vector<vector < vector<int> > >t;

int sum (int x, int y, int z) {
  long long result = 0;
  for (int i = x; i >= 0; i = (i & (i+1)) - 1)
    for (int j = y; j >= 0; j = (j & (j+1)) - 1)
        for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
            result += t[i][j][k];
  return result;
}
void add(int x, int y, int z, int amount) {
     for (int i = x; i < n; i += i & -i) {
         for (int j = y; j < n; j += j & -j) {
            for (int k = z; k < n; k+= k & -k) {
             t[i][j][k]+= amount;
         }
     }
 }
}



int main() {
    int n;
    cin >> n;
    vector< vector< vector<int> > > t(n , vector< vector<int> > (n, vector<int> (n, 0) ) );
    while(true) {
        int m;
        cin >> m;
        if (m == 3) {
            return 0; 
        } if (m == 1) {
            int x, y, z, amount;
            cin >> x >> y >> z >> amount;
            add(x, y, z, amount);
        } else {
            int x, y, z, x2, y2, z2;
            cin >> x >> y >> z >> x2 >> y2 >> z2;
            x2--; y2--; z2--;
            /*sum(x2,y2,z2)-sum(x2,y,z2)-sum(x2,y2,z)-sum(x,y2,z2)+sum(x2,y,z)+sum(x,y,z2)+sum(x,y2,z)-sum(x,y,z)<<endl;*/
            /*a = sum (x2, y2, z2);
            b = sum (x - 1, y - 1, z - 1);
            c = sum (x2, y2, z - 1) + sum (x2, y - 1, z2) + sum (x - 1 ,y2, z2);
            d = sum (x - 1, y - 1, z2) + sum (x - 1, y2, z - 1) + sum (x2, y - 1, z - 1);*/
            int a = sum(x2,y2,z2);
            int b = sum(x2,y,z2);
            int c = sum(x2,y2,z);
            int d = sum(x,y2,z2);
            int e = sum(x2,y,z);
            int f = sum(x,y,z2);
            int g = sum(x,y2,z);
            int h = sum(x,y,z);
            cout << a - b - c - d + e + f + g - h << endl;
        }
    }
}