#include <iostream>
#include<vector>
using namespace std;
#define ll long long


int main() {
    ll n;
    cin >> n;
    vector<vector<bool> > graph(n, vector<bool>(n, false));
    string s;
    for (ll i = 0; i < n; ++i) {
        cin >> s;
        for (ll j = 0; j < n; ++j) {
            if (s[j] == 'Y') {
                graph[i][j] = true;

            }
        }
    }
    vector<ll> dp(1 << n, 0);
    for (ll mask = 0; mask < (1 << n); ++mask)
        for (ll i = 0; i < n; ++i)
            if (mask & (1 << i))
                for (ll j = 0; j < n; ++j)
                    if (i != j and (mask&(1 << j)) and graph[i][j])
                        dp[mask] = max(dp[mask], dp[mask&(~(1 << i))&(~(1 << j))] + 2);


    ll best = 0;
    for (ll i = 0; i < (1 << n); ++i) {
        best = max(best, dp[i]);
    }
    cout << best;
}
