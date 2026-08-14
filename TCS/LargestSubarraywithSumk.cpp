#include<iostream>
#include<vector>
using namespace std;

int main(){

  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int k;
  cin>>k;

  unordered_map<int,int>mp;
  int prefix_sum = 0;
  int maxlen = 0;

  for(int i=0;i<n;i++){
    prefix_sum += arr[i];

    if(prefix_sum==k){
      maxlen = i+1;
    }

    if(mp.find(prefix_sum - k) != mp.end()) {
      maxlen = max(maxlen, i - mp[prefix_sum - k]);
    }

    if(mp.find(prefix_sum) == mp.end()){
      mp[prefix_sum] = i;
    }
  }

  cout<<maxlen<<endl;

  return 0;
}