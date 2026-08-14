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

  int cnt = 0;

  for(int i=0;i<n;i++){
    if(arr[i]==k){
      cnt++;
    }
  }

  if(cnt>=1){
    cout<<"True"<<endl;
  }
  else{
    cout<<"False"<<endl;
  }

  return 0;
}
