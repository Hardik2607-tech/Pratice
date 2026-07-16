#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &arr){
  int n = arr.size();
  int cur_sum = arr[0];
  int max_sum = arr[0];

  for(int i=1;i<n;i++){
    cur_sum = max(cur_sum+arr[i],arr[i]);
    max_sum = max(cur_sum,max_sum);
  }
  return max_sum;
}

int main(){
  int n;
  cout<<"";
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  cout<<solve(arr);
  return 0;
}