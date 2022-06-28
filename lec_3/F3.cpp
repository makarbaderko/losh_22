#include<iostream>
using namespace std;

int getInvCount(int arr[], int n)
{
	int invcount = 0;

	for (int i=1; i<n-1; i++)
	{
		int small = 0;
		for (int j=i+1; j<n; j++)
			if (arr[i] > arr[j])
				small++;

		int great = 0;
		for (int j=i-1; j>=0; j--)
			if (arr[i] < arr[j])
				great++;


		invcount += great*small;
	}

	return invcount;
}

int main()
{
  int l;
  cin >> l;
	int arr[l];
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << getInvCount(arr, n) << endl;n
	return 0;
}
