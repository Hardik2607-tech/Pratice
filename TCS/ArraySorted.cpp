#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  int cnt = 0;

  for(int i=0;i<n;i++){
    if(arr[i]>arr[(i+1)%n]){
      cnt++;
    }
  }


  if (cnt <= 1) {
    cout << "true" << endl;
  } 
  else {
    cout << "false" << endl;
  }

  return 0;
} 
