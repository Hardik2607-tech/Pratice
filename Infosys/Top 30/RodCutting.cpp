#include<iostream>
#include<vector>
using namespace std;

int rodcutting(vector<int> &length,
  vector<int> &price,int k){

  int m = length.size();
  int n = price.size();
  vector<vector<int>>dp(m+1,vector<int>(k+1,0));

  for(int i=1;i<=m;i++){
    for(int j=1;j<=k;j++){
      if(length[i-1]<=j){
        dp[i][j] = max(dp[i-1][j], dp[i][j-length[i-1]]+price[i-1]);
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[m][k];
}

int main(){
  int n;
  cin>>n;

  vector<int>length(n);

  for(int i=0;i<n;i++){
    cin>>length[i];
  }

  vector<int>price(n);

  for(int i=0;i<n;i++){
    cin>>price[i];
  }

  int k;
  cin>>k;
  cout<<rodcutting(length,price,k);
  return 0;
}