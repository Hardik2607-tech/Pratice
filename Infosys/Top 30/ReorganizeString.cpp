#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

string reorganise(string &s){

  int n = s.size();
  unordered_map<char,int>freq;

  for(char ch:s){
    freq[ch]++;
  }

  priority_queue<pair<int,char>> pq;

  for(auto it:freq){
    if(it.second > (n+1)/2){
      return "";
    }
    pq.push({it.second,it.first});
  }

  string ans = "";

  pair<int,char>prev = {0,'#'};

  while(!pq.empty()){

    auto cur = pq.top();
    pq.pop();

    ans += cur.second;
    cur.first--;

    if(prev.first>0){
      pq.push(prev);
    }

    prev = cur;
  }
  return ans;
}

int main(){
  
  string s;
  cin>>s;

  cout<< reorganise(s);
  return 0;
}