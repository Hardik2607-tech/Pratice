#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int sum(vector<string> &arr){

  int n = arr.size();
  stack<int>st;

  for(int i=0;i<n;i++){
    if(arr[i]!= "/" && arr[i]!= "*" &&
       arr[i]!= "+" && arr[i]!= "-"){
        st.push(stoi(arr[i]));
    }
    else {
      int s2 = st.top();
      st.pop();

      int s1 = st.top();
      st.pop();

      if(arr[i]=="+"){
        st.push(s1+s2);
      }
      else if(arr[i]=="-"){
        st.push(s1-s2);
      }
      else if(arr[i]=="*"){
        st.push(s1*s2);
      }
      else if(arr[i]=="/"){
        st.push(s1/s2);
      }
    }
  }
  return st.top();
}
int main(){
  
  int n;
  cin>>n;

  vector<string>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }


  cout<<endl<<sum(arr)<<endl;
  return 0;
}
