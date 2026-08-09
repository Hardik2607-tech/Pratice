#include<iostream>
#include<vector>
using namespace std;

string addition(string &s1,string &s2){

  int n = s1.size()-1;
  int m = s2.size()-1;
  int carry = 0;
  
  string ans = "";

  while(n>=0 || m>=0 || carry){

    int sum = carry;

    if(n>=0){
      sum += s1[n--] - '0';
    }

    if(m>=0){
      sum += s2[m--] - '0';
    }

    ans = char((sum % 2) + '0') + ans;
    carry = sum / 2;
  }
  return ans;
}

int main(){
  
  string s1;
  cin>>s1;

  string s2;
  cin>>s2;

  cout<<endl<<addition(s1,s2)<<endl;
  return 0;
}


