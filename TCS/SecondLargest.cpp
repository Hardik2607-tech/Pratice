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

  int largest = arr[0];
  int seclargest = INT_MIN;


  for(int i=0;i<n;i++){
    if(arr[i]>largest){
      seclargest = largest;
      largest = arr[i];
    }
    else if(arr[i]>seclargest&& arr[i] != largest){
      seclargest = arr[i];
    }
  }

  cout<<seclargest<<endl;


  return 0;
} 
