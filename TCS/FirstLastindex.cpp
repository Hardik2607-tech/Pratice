#include<iostream>
using namespace std;

int indexdiff(vector<int> &arr,int k){

  int n = arr.size();
  int low = 0;
  int high = n-1;
  int first = 0;
  int last = 0;

  while (low<=high){

    int mid = low + (high - low)/2;

    if(arr[mid]==k){
      first = mid;
      high = mid - 1;
    }
    else if(arr[mid]<k){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }

  low = 0;
  high = n-1;

  while (low<=high){

    int mid = low + (high - low)/2;

    if(arr[mid]==k){
      last = mid;
      low = mid + 1;
    }
    else if(arr[mid]<k){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  
  int diff = last - first;
  return diff;
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

  sort(arr.begin(),arr.end());
  cout<<indexdiff(arr,k);

  return 0;
}