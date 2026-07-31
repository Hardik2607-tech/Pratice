#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longsubstr(string s) {
  //unordered_map<char,int> mp;
  int n = s.size();
  int hashlen = 256;
  int hash[hashlen];

  for(int i = 0; i < 256; i++){
    hash[i] = -1;    
  }
  int l = 0;
  int r = 0;
  int maxlen = 0;

  while(r<n){

    if(hash[s[r]] != -1){
      l = max(hash[s[r]]+1,l);
    }

    int len = r - l + 1;
    maxlen = max(len,maxlen);

    hash[s[r]] = r;
    r++;
  }

  return maxlen;
}

int main() {
  string s;
  cin>>s;

  cout << longsubstr(s) << endl;
  
  return 0;
}