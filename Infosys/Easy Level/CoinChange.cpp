#include<iostream>
#include<vector>
using namespace std;


int coinchange(int &sum,vector<int> &coins){
    int n = coins.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

    for(int i=0;i<=n;i++){
      dp[i][0] = 1;
    }
    
    for(int i=1;i<=n;i++){
      for(int j=1;j<=sum;j++){
        if(coins[i-1]<=j){
          dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    return dp[n][sum];
}


int main(){

  int sum;
  cin>>sum;

  int n;
  cin>>n;

  vector<int>coins(n);

  for(int i=0;i<n;i++){
    cin>>coins[i];
  }

  cout<<coinchange(sum,coins);
  return 0;
}