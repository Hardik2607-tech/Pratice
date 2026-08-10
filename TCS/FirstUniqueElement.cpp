#include<iostream>
using namespace std;

int unique(vector<int> &arr){
  
  unordered_map<int,int>mp;

  for(int x:arr){
    mp[x]++;
  }

  for(int x:arr){
    if(mp[x]==1){
      return x;
    }
  }
  return -1;
}

int main(){
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cout<<unique(arr);

  return 0;
}