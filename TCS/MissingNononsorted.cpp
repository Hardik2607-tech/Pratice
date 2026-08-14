#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
  
  int n;
  cin>>n;

  vector<int>arr(n);
  unordered_map<int,int>mp;

  for(int i=0;i<n;i++){
    cin>>arr[i];
    mp[arr[i]]++;
  }
  
  int dup = 0;
  int miss = 0;

  for(int i=1;i<n;i++){
    if(mp[i]==0){
      miss = i;
    }
    if(mp[i]==2){
      dup = i;
    }
  }

  cout<<dup<<endl;
  cout<<miss<<endl;

  return 0;
}
