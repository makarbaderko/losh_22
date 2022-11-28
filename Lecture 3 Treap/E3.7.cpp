#include<iostream>
using namespace std;

int getInversions(int * A, int n) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (A[i] > A[j]) {
        ++count;
      }
    }
  }n
  return count;
}

int main(){
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  string req;
  for (int i = 0; i < m; i++){
    cin >> req;
    if(req == "0"){
      cout << getInversions(arr, sizeof(arr));
    } else {
      int l, r;
      swap(arr[l], arr[r]);
    }
  }
}
