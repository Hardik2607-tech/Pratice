#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int k;
  cin>>k;

  string s;
  cin>>s;

  int white = 0;

  for(int i=0;i<k;i++){
    if(s[i] == 'W'){
      white++;
    }
  }

  int ans = white;

  for(int i=k;i<n;i++){
    if(s[i - k] == 'W'){
      white--;
    }
    if (s[i] == 'W'){
      white++;
    }
    ans = min(ans, white);
  }

  cout<<endl<<ans;

  return 0;
}