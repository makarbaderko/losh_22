#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
  vector<long long> ans;
  string s, t;
  cin >> t >> s;
  const int osn = 31;
  vector<long long> osn_pow (max (s.length(), t.length()));
  osn_pow[0] = 1;
  for (size_t i=1; i<osn_pow.size(); ++i)
  	osn_pow[i] = osn_pow[i-1] * osn;
  vector<long long> hashes (t.length());
  for (size_t i=0; i<t.length(); ++i)
  {
  	hashes[i] = (t[i] - 'a' + 1) * osn_pow[i];
  	if (i){
      hashes[i] += hashes[i-1];
    }
  }
  long long h_s = 0;
  for (size_t i=0; i<s.length(); ++i)
  	h_s += (s[i] - 'a' + 1) * osn_pow[i];
  for (size_t i = 0; i + s.length() - 1 < t.length(); ++i)
  {
  	long long hash = hashes[i+s.length()-1];
  	if (i){
      hash -= hashes[i-1];
    }
  	if (hash == h_s * osn_pow[i])
  		ans.push_back(i + 1);
  }
    cout << ans.size() << endl;
    for (auto i : ans) {
      cout << i << ' ';
    }
    cout << endl;
}
