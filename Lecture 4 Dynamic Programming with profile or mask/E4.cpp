#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    if (m<n){
      int temp = n;
      n = m;
      m = temp;
    }
    long long dp[1 << n][1 << n];
    long long a[m][1<< n];
    memset(dp, 0, sizeof(dp));
    memset(a,0, sizeof(a));
    for (long long i = 0; i < (1 << n); i++) {
        for (long long j = 0; j < (1 << n); j++) {
            long long mask = j&i;
            long long nmask =((~i) & (~j)) & ((1<<n)-1);
            if ((!(nmask & (nmask << 1))) and (!(mask & (mask << 1)))){
                dp[i][j]=1;
            }
        }
    } for (long long i = 0; i <(1<<n); i++) {
        a[0][i]=1;
    }
    for (long long i = 1; i < m; i++) {
        for (long long j = 0; j < (1<<n); j++) {
            for (long long k = 0; k < (1<<n); k++) {
                a[i][j] += (a[i-1][k] * dp[k][j]);
            }
        }
    }
    long long sum = 0;
    for (long long i = 0; i < (1 << n); i++) {
        sum += a[m - 1][i];
    }
    cout << sum << endl;
}
