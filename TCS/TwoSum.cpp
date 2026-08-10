#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twosum(vector<int> &nums,int target){

  int n = nums.size();
  unordered_map<int,int>mp;

  for(int i=0;i<n;i++){
    int x = target-nums[i];
    if(mp.find(x) != mp.end()){
      return {mp[x],i};
    }
    mp[nums[i]]= i;
  }
  return {};
}

int main(){

  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int k;
  cin>>k;

  vector<int> ans = twosum(arr,k);


  cout<<ans[0]<<" "<<ans[1];
  return 0;
}