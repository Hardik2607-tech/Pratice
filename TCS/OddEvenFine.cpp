#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  vector<int>veh(n);

  for(int i=0;i<n;i++){
    cin>>veh[i];
  }

  int d;
  cin>>d;

  int X;
  cin>>X;

  int cnt = 0;

  for(int i=0;i<n;i++){
    if(veh[i] % 2 != d % 2){
      cnt++;
    }
  }
  
  int ans = X * cnt;

  cout<<ans;

  return 0;
} 


