#include<iostream>
#include<vector>
using namespace std;

long index(vector<int> &arr){

  int n = arr.size();

  vector<pair<int,int>>nums;

  for(int i=0;i<n;i++){
    nums.push_back({arr[i],i});
  }

  long ans = 0;
  sort(nums.begin(),nums.end());

  for(int i=0;i<n;i++){
    ans += abs(nums[i].second - i);
  }

  return ans;
}

int main(){
  
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cout<<index(arr);
  return 0;
}


