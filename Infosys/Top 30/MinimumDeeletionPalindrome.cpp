#include<iostream>
using namespace std;

int  mindel(string &s){
  int n = s.size();
  string r = s;
  reverse(s.begin(),s.end());

  vector<vector<int>>dp(n+1,vector<int>(n+1,0));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(s[i-1]==r[i-1]){
        dp[i][j] = 1+dp[i-1][j-1];
      }
      else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  int ans = dp[n][n];
  return n-ans;
}

int main(){
  
  string s;
  cin>>s;

  cout<< mindel(s);
  return 0;
}