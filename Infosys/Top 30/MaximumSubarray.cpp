#include<iostream>
#include<vector>
using namespace std;

int  maximumsub(vector<int> &nums){

  int n = nums.size();
  int cursum = nums[0];
  int maxsum = nums[0];

  for(int i=1;i<n;i++){
    cursum = max(nums[i],nums[i]+cursum);
    maxsum = max(cursum,maxsum);
  }
  return maxsum;
}

int main(){
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cout<<maximumsub(arr);
  return 0;
}