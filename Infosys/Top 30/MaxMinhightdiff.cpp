#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int  maxmindiff(vector<int> &arr,int k){

  int n = arr.size();
  sort(arr.begin(),arr.end());
  int ans = arr[n-1] - arr[0];

  for(int i=0;i<n;i++){


    int mindiff = min(arr[0] + k,arr[i+1]-k);
    int maxdiff = max(arr[n-1] - k,arr[i]+k);


    if(mindiff < 0) continue;
    ans = min(ans, maxdiff - mindiff);
  }
  return ans;
}

int main(){
  int n;
  cin>>n;

  vector<int>height(n);

  for(int i=0;i<n;i++){
    cin>>height[i];
  }

  int k;
  cin>>k;

  cout<< maxmindiff(height,k);

  return 0;
}