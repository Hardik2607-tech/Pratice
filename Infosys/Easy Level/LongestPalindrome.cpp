#include<iostream>
#include<string>
using namespace std;

string longestpalindrome(string &s){
  vector<int> freq(26, 0);

    for(char ch : s){
      freq[ch - 'A']++;
    }
    string left = "";
    string mid = "";

    for(int i = 0; i < 26; i++) {
      left += string(freq[i] / 2, char(i + 'A'));
      if(freq[i] % 2 == 1 && mid == ""){
        mid += char(i + 'A');
      }
    }

    string right = left;
    reverse(right.begin(), right.end());

    return left + mid + right;
}

int main(){
  string s;
  cin>>s;

  cout<<longestpalindrome(s);
  return 0;
}