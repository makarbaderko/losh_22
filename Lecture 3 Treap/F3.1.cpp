#include <iostream>
#include <algorithm>
using namespace std;


long long bit[100][100000] = { 0 };


void permut(long long arr[], long long N)
{
	long long temp[N];
	for (long long i = 0; i < N; i++)
	{
	temp[i] = arr[i];
	}
	sort(temp, temp + N);
	for (long long i = 0; i < N; i++)
	{
		long long* lb = lower_bound(temp, temp + N, arr[i]);
		arr[i] = (lb - temp) + 1;
	}
}


void update(long long l, long long i, long long val, long long n)
{
    while (i <= n)
    {
        bit[l][i] = bit[l][i] + val;
        i = i + (i & (-i));
    }
}


long long findSum(long long l, long long i)
{
    long long sum = 0;
    while (i > 0)
    {
        sum = sum + bit[l][i];
        i = i - (i & (-i));
    }
    return sum;
}


long long inversions(long long arr[], long long n, long long k)
{
	for (long long i = n - 1; i >= 0; i--)
	{
		long long curr = arr[i];
		update(1, curr, 1, n);
		for (long long j = 1; j < k; j++)
		{
			long long s = findSum(j, curr - 1);
			update(j + 1, curr, s, n);
		}
	}
	return findSum(k, n);
}


int main()
{
	long long n;
  cin >> n;
	long long arr[n];
  for (long long i = 0; i < n; i++){
    cin >> arr[i];
  }
	permut(arr, n);
	cout << inversions(arr, n, 3) << endl;
	return 0;
}
