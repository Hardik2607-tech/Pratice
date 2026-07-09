#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxi = nums[0];
    int mini = nums[0];
    int ans = nums[0];

    for (int i = 1; i < n; i++) {
      if (nums[i] < 0){
        swap(maxi, mini);
      }
      maxi = max(nums[i], maxi * nums[i]);
      mini = min(nums[i], mini * nums[i]);
      ans = max(ans, maxi);
    }
    return ans;
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

  cout << maxProduct(nums) << endl;
  return 0;
}