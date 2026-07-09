#include<iostream>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (temp[j] > temp[i]) {
          ans[i] = j - i;
          break;
        }
      }
    }

    return ans;
}

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  
  vector<int>temp(n);

  cout<<"Enter temperatures: ";
  for(int i=0;i<n;i++){
    cin>>temp[i];
  }

  vector<int> ans = dailyTemperatures(temp);

    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
  return 0;
}