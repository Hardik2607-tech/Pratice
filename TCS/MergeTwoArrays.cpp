#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

  int n;
  cin>>n;

  vector<int> a(n);

  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  
  sort(a.begin(),a.end());
  cout<<endl;

  int m;
  cin>>m;

  vector<int> b(m);

  for(int i=0;i<m;i++){
    cin>>b[i];
  }

  sort(b.begin(),b.end(), greater<int>());

  int i=0;
  int j= m - 1;
  cout<<endl;

  while(i<n && j>=0){

    if(a[i]<b[j]){
      cout<<a[i]<<" ";
      i++;
    }
    else{
      cout<<b[j]<<" ";
      j--;
    }
  }

  while(i<n){
    cout<<a[i]<<" ";
    i++;
  }

  while(j>=0){
    cout<<b[j]<<" ";
    j--;
  }

  return 0;
}