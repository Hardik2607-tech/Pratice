#include<iostream>
#include<vector>
using namespace std;

int  MaximumProduct(vector<int> &nums){

  int n = nums.size();
  int maxprod = nums[0];
  int minprod = nums[0];
  int ans = nums[0];

  for(int i=1;i<n;i++){
    if(nums[i]<0){
        swap(maxprod,minprod);
    }
    minprod = min(nums[i],nums[i]*minprod);
    maxprod = max(nums[i],nums[i]*maxprod);

    ans = max(ans,maxprod);
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

  cout << MaximumProduct(arr);
  return 0;
}