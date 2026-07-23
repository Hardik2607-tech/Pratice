#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int k;
  cin>>k;

  sort(arr.begin(),arr.end());
  
  int ans = arr[n - 1] - arr[0];
  int l = n-1;

  for (int i = 1; i < n; i++) {
    int smallest = min(arr[0] + k, arr[i] - k);
    int largest = max(arr[l] - k, arr[i - 1] + k);
    ans = min(ans, largest - smallest);
  }

  cout << ans;
  return 0;
}