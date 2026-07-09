#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int longstring(vector<char>&str){
  unordered_map<char, int> lastIndex;
  int left = 0;
  int ans = 0;

  for (int right = 0; right < str.size(); right++) {
    if (lastIndex.count(str[right]) && lastIndex[str[right]] >= left) {
      left = lastIndex[str[right]] + 1;
    }
    lastIndex[str[right]] = right;
    ans = max(ans, right - left + 1);
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