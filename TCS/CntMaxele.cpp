#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  if(n == 0){
    cout<<0;
  }
  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int cnt=1;
  int maxi = arr[0];

  for(int i=0;i<n;i++){
    if(arr[i]>maxi){
      maxi = arr[i];
      cnt++;
    }
  }
  
  cout<<cnt;
  
  return 0;
} 


