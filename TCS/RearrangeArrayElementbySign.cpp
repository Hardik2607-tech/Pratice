#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;

  vector<int>arr(n);
  vector<int>res(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int pos = 0;
  int neg = 1;

  for(int i=0;i<n;i++){
    if(arr[i]>0){
      res[pos] = arr[i];
      pos += 2;
    }
    else{
      res[neg] = arr[i];
      neg += 2;
    }
  }

  for(int i=0;i<n;i++){
    cout<<res[i]<<" ";
  }

  return 0;
}