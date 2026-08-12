#include<iostream>
using namespace std;

int fact(int n){

  return n*(n-1);
}

int main(){

  int n;
  cin>>n;

  if(n==1) return 1;
  
  cout<<fact(n)<<endl;
  return 0;
} 


