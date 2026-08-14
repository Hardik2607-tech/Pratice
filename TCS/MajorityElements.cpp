#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int count = 0;
  int candidate = 0;

  for(int i=0;i<n;i++){
    if(count==0){
      candidate = arr[i];
      count = 1;
    }

    else if(candidate==arr[i]){
      count++;
    }

    else{
      count--;
    }
  }
  
  cout<<candidate<<endl;

  return 0;
}

  // int mini = int(n/3) + 1;

  // unordered_map<int,int>mp;
  // vector<int>res;

  // for(int i=0;i<n;i++){
  //   mp[arr[i]]++;

  //   if(mp[arr[i]]==mini){
  //     res.push_back(arr[i]);
  //   }

  //   if(res.size() == 2){
  //     break;
  //   }
  // }

  // for(int i=0;i<res.size();i++){
  //   cout<<res[i]<<" ";
  // }
