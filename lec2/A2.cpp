#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*rsq(x1, y1, x2, y2) = rsq(0, 0, x2, y2) - rsq(0, 0, x1-1, y2) - 
- rsq(0, 0, x2, y1-1) + rsq(0, 0, x1-1, y1-1). */
vector< vector<int> > gr;

void add(int x, int y, int n) {
      for (int i = x; i < n; i += i & -i) {
          for (int j = y; j < n; j += j & -j) {
              gr[i][j]++;
          }
      }
  }


int sum(int x1, int y1, int x2, int y2) {
    int ans; 
    for (int i = x1; i < x2; i ++) {
        for (int j = y1; j < y2; j++) {
            ans += gr[i][j];
        }
    }
    return ans;
}

int main() {
    int n, k;
    gr.resize(n);
    for (int i = 0; i < k; i++){
        cout << "main started" << endl;
        string req;
        cin >> req;
        cout << req << endl;
        if (req == "ADD") {
            int x, y;
            cin >> x >> y;
            add(x, y, n);
            cout << "added" << endl;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int ans;
            ans = sum(x1, y1, x2, y2);
            cout << ans << endl;
        }
    }
}
