#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

  string s;
  cin>>s;


  unordered_map<char,int>mp;

  for(char x:s){
    mp[x]++;
  }

  for(char x:s){
    if(mp[x]==1){
      cout<<x;
      break;
    }
  }
  return 0;
}