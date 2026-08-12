#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  if(n == 0){
    cout<<0;
  }
  
  int prod = 1;
  
  while(n>0){
    prod *= n%10;
    n = n/10;
  }

  cout<<prod;

  return 0;
} 
