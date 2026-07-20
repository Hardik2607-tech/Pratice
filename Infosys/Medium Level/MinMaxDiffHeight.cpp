#include<iostream>
#include<vector>
using namespace std;

int maxmindiff(vector<int> &arr,int k){

  int n = arr.size();
  sort(arr.begin(),arr.end());
  int res = arr[n-1] - arr[0];

  for(int i=1;i<n;i++){
    if(arr[1] - k <0){
      continue;
    }

    int minH = min(arr[0]+k,arr[i]-k);
    int maxH = max(arr[i-1]+k,arr[n-1]-k);
    int diff = maxH - minH;
    res = min(res,diff);
  }
  return res;
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

  cout<<maxmindiff(arr,k)<<endl;
  return 0;
}