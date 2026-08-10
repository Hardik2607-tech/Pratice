#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int m;
  cin>>m;

  vector<int>arr(m);

  for(int i=0;i<m;i++){
    cin>>arr[i];
  }

  if(n!=m){
    cout<< -1;
  }

  unordered_map<int,int>mp;
  vector<int>res;

  for(int x:arr){
    if(mp.find(x) == mp.end()){
      mp[x]++;
      res.push_back(x);
    }
  }

  reverse(res.begin(),res.end());

  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
  }

  return 0;
}