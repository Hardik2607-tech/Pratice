#include<iostream>
using namespace std;

int main(){
  string s;
  cin>>s;

  int ans = 0;

  for(char ch:s){
    if(ch=='v'){
      ans+=1;
    }
    if(ch=='w'){
      ans+=2;
    }
  }
  cout<<ans;
  return 0;
}