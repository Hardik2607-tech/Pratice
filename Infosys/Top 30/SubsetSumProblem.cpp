#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool subsum(vector<int> &arr,int sum){
  int n = arr.size();

  vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));

  for(int i=0;i<n;i++){
    dp[i][0] = true;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
      if(arr[i-1]<=j){
        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][sum];
}

int main(){
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int sum;
  cin>>sum;

  cout<< subsum(arr,sum);
  return 0;
}