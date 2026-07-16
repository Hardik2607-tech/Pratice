#include<iostream>
#include<stack>
using namespace std;

int cal(vector<string> &tokens){

  stack<int>st;

  for(string t:tokens){
    if(t == "+" || t == "-" ||
      t == "*" || t == "/") {

      int b = st.top();
      st.pop();

      int a = st.top();
      st.pop();

      if(t == "+"){
        st.push(a + b);
      }
      else if(t == "-"){
        st.push(a - b);
      }
      else if(t == "*"){
        st.push(a * b);
      }
      else{
        st.push(a / b);
      }
    }
    else{
      st.push(stoi(t));
    }
  }
  return st.top();
}

int main(){

  int n;
  cout<<"";
  cin>>n;

  vector<string>tokens(n);

  for(int i=0;i<n;i++){
    cin>>tokens[i];
  }

  cout<<cal(tokens);
  return 0;
}

