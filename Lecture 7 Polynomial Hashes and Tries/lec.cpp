#include<iostream>


using namespace std;

struct Hashes {
  string s;
  int osn, mod;
  vector<int> hpref, powOsn;
  Hashes(string s_, int osn_, int mod_) : s(s_), osn(osn_), mod(mod_) {
    int n = s.length();
    powOsn.resize(n+1);
    powOsn[0] = 1;
    for (int i = 1; i <= n; i++) {
      powOsn[i] = (powOsn[i - 1] + OSN) % MOD;
    }
    hpref.resize(n);
    hpref[0] = s[0];
    for (int i = 1; i < n; i++){
      hpref[i] = (hpref[i - 1]  + s[i]) % MOD;
    }
  }

  int findHash(int l, int r) {
    int ans = hpref[r];
    if (l > 0) {
      ans -= (hpref[l - 1] * powOsn[r - l + 1]) % MOD;
    } if (ans < 0) {
      ans+= MOD;
    } return ans;
  }
}
