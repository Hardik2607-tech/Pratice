#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int k;
  cin>>k;

  if(n == 0){
    cout<<0;
    return 0;
  }
  
  int sum = 0;
  int res = 0;
  int prod = 0;

  while(n>0){
    sum += n%10;
    n = n/10;
  }

  res = sum * k;

  while(res>0){
    prod += res%10;
    res = res/10;
  }
  cout<<prod<<endl;

  return 0;
} 
