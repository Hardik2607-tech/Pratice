#include<iostream>
#include<vector>
using namespace std;

bool equalsum(vector<int> &nums){

  int n = nums.size();
  int total = 0;

  for(int i=0;i<n;i++){
    total += nums[i];
  }

  if(total % 2 !=0){
    return false;
  }
  int target = total / 2;

  vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

  for(int i=0;i<=n;i++){
    dp[i][0] = true;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=target;j++){
      if(nums[i-1]<=j){
        dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
      }
      else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  return dp[n][target];
}

int main(){
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  if(equalsum(arr)){
    cout<< "True";
  }
  else{
    cout<< "False";
  }
  return 0;
}