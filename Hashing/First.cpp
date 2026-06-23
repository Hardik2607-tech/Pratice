#include<iostream>
using namespace std;

int f(int k,int n,int arr[]){
  int count = 0;
  for(int i=0;i<n;i++){
    if(arr[i]==k){
      count +=1;
    }
  }
  return count;
}
int main() {
  int n;// arr size 
  cout<<"Enter n: ";
  cin>>n;

  int arr[n]; // arr define
  for(int i=0;i<n;i++){
    cout<<"Enter Arr["<<i<<"]: ";
    cin>>arr[i];
  }
  int k; // target
  cout<<"Enter k: ";
  cin>>k;

  cout<<f(k,n,arr); // function calling
  
  return 0;
}