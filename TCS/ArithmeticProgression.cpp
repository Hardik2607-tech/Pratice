#include<iostream>
using namespace std;

int main(){

  int a;
  cin>>a;

  int d;
  cin>>d;

  int n;
  cin>>n;

  for(int i=0;i<n;i++){
    cout<<a + i * d<<" ";
  }

  return 0;
}