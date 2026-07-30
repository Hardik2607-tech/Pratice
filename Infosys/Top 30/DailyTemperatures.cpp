#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>  dailytemp(vector<int> &temp){

  int n = temp.size();
  stack<int>st;
  vector<int>ans(n,0);

  for(int i=0;i<n;i++){
    while(!st.empty() && temp[i] > temp[st.top()]){
      int cur = st.top();
      st.pop();

      ans[cur] = i - cur;
    }
    st.push(i);
  }
  return ans;
}

int main(){
  int n;
  cin>>n;

  vector<int>temp(n);

  for(int i=0;i<n;i++){
    cin>>temp[i];
  }

  vector<int> ans = dailytemp(temp);

  for(int i=0;i<n;i++){
    cout<< ans[i]<< " ";
  }

  return 0;
}