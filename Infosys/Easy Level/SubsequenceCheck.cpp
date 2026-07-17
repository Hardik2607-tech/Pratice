#include<iostream>
using namespace std;

int main(){
  string s;
  cin>>s;

  string target = "Hello";
  int n = s.size();

  int j=0;
  for(char ch:s){
    if(ch==target[j]){
      j++;
    }
  }

  if(j==n){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }

  return 0;
}