#include<iostream>
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

  for(int i=0;i<n;i++){
    if(arr[i]==k){
      cout<<i<<" ";
    }
  }

  return 0;
}