#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  unordered_map<int,int>mp;
  int duplicate = -1;
  int missing = -1;

  for(int x:arr){
    mp[x]++;
  }

  for(int i=0;i<n;i++){
    if(mp[i]==2){
      duplicate = i;
    }
    if(mp[i]==0){
      missing = i;
    }
  }
  
  cout<<duplicate<<endl;
  cout<<missing<<endl;

  return 0;
}