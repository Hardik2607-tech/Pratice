#include<iostream>
#include<vector>
using namespace std;

int binsearch(vector<int>&nums){
  int n = nums.size();
  int left = 0;
  int right = n-1;

  while(left<right){
    int mid = left + (right-left)/2;

    if(nums[mid]<nums[mid+1]){
      left= mid + 1;
    }
    else{
      right = mid;
    }
  }
  return left;
}

int main(){
  int n;
  cout<<"Enter N: ";
  cin>>n;

  vector<int>nums(n);

  cout<<"Enter : ";
  for(int i=0;i<n;i++){ 
    cin>>nums[i];
  }

  cout << binsearch(nums) << endl;
  return 0;
}