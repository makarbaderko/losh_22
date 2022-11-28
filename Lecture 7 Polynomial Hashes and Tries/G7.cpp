/*
#include<iostream>
using namespace std;

int dp[20][1 << 19];
int main()
{
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 1; i <= n; i++){
		cin >> x;
		if (!dp[0][x]){
			for (int j = 0; j < 20; j++){
				int temp = x >> j;
				dp[j][temp]++;
			}
		}
	}
	int c = 0;
	for (int i = 1 ; i <= m;i++){
		cin >> x;
		c ^= x;
		int ans = 0;
		for (int j = 19;j >= 0;j--){
			if (dp[j][(ans ^ c) >> j] == (1 << j))
				ans |= (1 << j);
		}
		cout << ans << endl;
	}
	return 0;
}
*/

#include <iostream>

using namespace std;


int n;
int m;
int x
int dp[25][1<<19];
int main{
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> x;
        if(!dp[0][x]){
            for(int j=0; j<=19; j++){
                dp[j][x >> j] += 1;
            }
        }
    }
    int z=0;
    for(int i=1; i <= m ;i++){
        int y;
        cin >> y;
        int ans=0;
        z=z^y;
        for(int j=19;j>=0;j--){
            if((dp[j][(ans^z)>>j] == (1 << j))){
                ans |= (1<<j);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
