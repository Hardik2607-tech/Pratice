#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longsubstr(string s) {
  unordered_map<char,int> mp;
  int n = s.size();
  int left = 0;
  int ans = 0;

  for(int right = 0; right < n; right++){

    if(mp.count(s[right])){
      left = max(left, mp[s[right]] + 1);
    }
    mp[s[right]] = right;
    ans = max(ans, right - left + 1);
  }
  return ans;
}

int main() {
  string s;
  cin>>s;

  cout << longsubstr(s) << endl;
  
  return 0;
}