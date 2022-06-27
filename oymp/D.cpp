#include<iostream>
#include <string>
#include<cmath>
using namespace std;

bool IsSquare(long long k) {
   float x = sqrt(k);
   return ((x - floor(x)) == 0);
 }

int main() {
  long long ans = 0;
  long long n;
  bool flag;
  cin >> n;
  for (double i = 0; i < n; i++){
    flag = true;
    string ii = to_string(i);
    for (double j = 0; j < ii.length(); j++) {
      string sub =  ii.substr(j, ii.length());
      if (!IsSquare(stoi(sub))){
        flag = false;
      }
    }
    if(flag){
      ans++;
    }
    }
  ans--;
  cout << ans << endl;
}
