#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int longstring(vector<char>&str){
  unordered_map<char, int> lastIndex;
  int l = 0;
  int ans = 0;
  int n = str.size();

  for (int r = 0; r < n; r++) {
    if (lastIndex.count(str[r]) && lastIndex[str[r]] >= l) {
      l = lastIndex[str[r]] + 1;
    }
    lastIndex[str[r]] = r;
    ans = max(ans, r - l + 1);
  }

  return ans;
}

int main(){
  int n;
  cout<<"Enter N: ";
  cin>>n;

  vector<char>str(n);

  cout<<"Enter : ";
  for(int i=0;i<n;i++){ 
    cin>>str[i];
  }

  cout << longstring(str);

  return 0;
}