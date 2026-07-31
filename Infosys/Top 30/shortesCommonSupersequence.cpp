#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int scs(string &s1,string &s2){
  int n1 = s1.size();
  int n2 = s2.size();

  vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
  
  for(int i=1;i<=n1;i++){
    for(int j=1;j<=n2;j++){
      if(s1[i-1]==s2[j-1]){
        dp[i][j] = 1 + dp[i-1][j-1];
      }
      else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  int ans = dp[n1][n2];
  return n1+n2 - ans;
}

int main(){

  string string1;
  cin>>string1;

  string string2;
  cin>>string2;

  cout<< scs(string1,string2);
  return 0;
}