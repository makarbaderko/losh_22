#include <vector>
#include <string>
#include <iostream>


using namespace std;

vector <vector <int> > t;
int n;

int sum (int x, int y) {
  int result = 0;
  for (int i = x; i >= 0; i = (i & (i+1)) - 1)
    for (int j = y; j >= 0; j = (j & (j+1)) - 1)
      result += t[i][j];
  return result;
}

void add (int x, int y, int delta) {
  for (int i = x; i < n; i = (i | (i+1)))
    for (int j = y; j < n; j = (j | (j+1)))
      t[i][j] += delta;
}

void change(int x, int y, int delta) {
  for (int i = x; i < n; i = (i | (i+1)))
    for (int j = y; j < n; j = (j | (j+1)))
      t[i][j] = delta;
}

int main() {
    int n;
    cin >> n;
    string ask;
    t = vector<vector<int> >(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++){
      int x, y, w;
      cin >> x >> y >> w;
      add(x, y, w);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> ask;
      if (ask == "change"){
        int i, z;
        cin >> i >> z;
        change(i, z);
      } else {
        int rx, ry;
        cin >> rx >> ry;
        cout << sum(rx, ry) << endl;
      }
    }
    return 0;
}
