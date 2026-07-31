#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinchange(vector<int>coins,int amount){
  int n = coins.size();
  vector<vector<int>>dp(n+1,vector<int>(amount+1,1e9));

  dp[0][0] = 0;

  for (int i = 1; i <= n; i++){
    dp[i][0] = 0;
    }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=amount;j++){
      if(coins[i-1]<=j){
        dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  if(dp[n][amount] == 1e9){
    return -1;
  }
    else{
    return dp[n][amount];
  }
}

int main(){

  int n;
  cin>>n;

  vector<int>coins(n);

  for(int i=0;i<n;i++){
    cin>>coins[i];
  }

  int target;
  cin>>target;

  cout<<coinchange(coins,target);
  return 0;
}