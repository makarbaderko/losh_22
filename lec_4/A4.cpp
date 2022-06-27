#include <iostream>
#include<vector>
#include<string>
using namespace std;


int main() {
  int n;
  cin >> n;
  vector<vector<bool> > gr(n, vector<bool>(n, false));
  string input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    for (int j = 0; j < n; j++){
      if (input[j] == 'Y'){
        gr[i][j] = true;
      }
  }
  }
  vector<int>dp(1 << n, 0);
  for (int mask = 0; mask < (1 << n); mask++){
    for (int i = 0; i < n; i++){
      if(mask & (1 << i)) {
        for(int k = 0; k < n; k++){
        if (i != k and (mask & (1 << k)) and gr[i][k]){
          dp[mask] = max(dp[mask], dp[mask&(~(1 << i) & (~(1 << k)))] + 2);
        }
        }
      }
    }
  }
  int res = 0;
  for (int i  = 0; i < (1 << n); i++){
    res = max(res, dp[i]);
  }
  cout << res << endl;
  return 0;
}
