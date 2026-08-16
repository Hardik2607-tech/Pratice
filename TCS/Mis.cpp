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

  int mis = 0;
  int sum = 0;
  int expectedsum = n * (n+1)/2;

  for(int i=0;i<n;i++){
    sum += arr[i];
  }
  
  mis = expectedsum - sum;

  cout<<mis;

  return 0;
}