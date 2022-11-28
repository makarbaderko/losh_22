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

void add (int x, int y) {
  for (int i = x; i < n; i = (i | (i+1)))
    for (int j = y; j < n; j = (j | (j+1)))
      t[i][j]++;
}


int main() {
    int k;
    cin >> n >> k;
    string ask;
    int x1, y1, x2, y2;
    t = vector<vector<int> >(n, vector<int> (n, 0));

    for (int i = 0; i < k; ++i) {
        cin >> ask;
        if (ask == "ADD") {
            cin >> x1 >> y1;
            add(x1 - 1, y1 - 1);
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            x2--;
            y1--;
            y2--;
            if (x1 > x2){
                int temp = x2;
                x2 = x1;
                x1 = temp;
            }
            if (y1 > y2){
                int temp = y2;
                y2 = y1;
                y1 = temp;
            }
            cout << sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1) << endl;
        }
    }

    return 0;
}
