#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int largest(vector<int> &arr,int k){

  priority_queue<int,
  vector<int>,
  greater<int>>pq;

  for(int x:arr){
    pq.push(x);

    if(pq.size()>k){
      pq.pop();
    }
  }
  return pq.top();
}
int main(){
  
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int k;
  cin>>k;

  cout<<largest(arr,k);
  return 0;
}
