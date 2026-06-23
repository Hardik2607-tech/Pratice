#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;

  vector<int> num(n);
  for(int i=0;i<n;i++){
    cin>>num[i];
  }

  map<int,int> freq;

  for(int i=0;i<n;i++){
    freq[num[i]]++;
  }
  cout<<endl;

  for(auto it:freq){
    cout<<it.first<<" "<<it.second<<endl;  
  }

  return 0;
}