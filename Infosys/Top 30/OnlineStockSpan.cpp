#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>  stockspan(vector<int> &price){

  int n = price.size();
  vector<int> span(n);
  stack<int> st;

  for (int i = 0; i < n; i++) {
      
    while (!st.empty() && price[st.top()] <= price[i]) {
      st.pop();
    }

    if(st.empty()){
      span[i] = i + 1;
    }
     else{
      span[i] = i - st.top();
    }
    st.push(i);
  }
  return span;
}

int main(){
  int n;
  cin>>n;

  vector<int>stock(n);

  for(int i=0;i<n;i++){
    cin>>stock[i];
  }

  vector<int> ans = stockspan(stock);

  for(int i=0;i<n;i++){
    cout<< ans[i]<< " ";
  }

  return 0;
}