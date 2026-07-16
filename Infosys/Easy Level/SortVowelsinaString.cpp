#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isvowel(char ch){
  return ch =='a' || ch =='A' ||
         ch =='e' || ch =='E' ||
         ch =='i' || ch =='I' || 
         ch =='o' || ch =='O' ||
         ch =='u' || ch =='U';
}

int main(){
  string s;
  cout<<" ";
  cin>>s;
  vector<char>vowels;
  int n = s.size();

  for(char ch:s){
    if(isvowel(ch)){
      vowels.push_back(ch);
    }
  }
  
  sort(vowels.begin(),vowels.end());

  int j = 0;
  for(int i=0;i<n;i++){
    if(isvowel(s[i])){
      s[i] = vowels[j++];
    }
  }
  cout<<s<<endl;
  return 0;
}