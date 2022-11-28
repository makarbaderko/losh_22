#include <iostream>
#include <vector>

using namespace std;


int main() {
  int n, k;
  cin >> n, k;
  vector<vector< int> > data(n, vector<int> (k));
  fill(data.begin(), data.end(), 0);
  memset(data, 0, sizeof(data));
  for (int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> newVec{a, b, c};
    data[i] = newVec;
  }
}
