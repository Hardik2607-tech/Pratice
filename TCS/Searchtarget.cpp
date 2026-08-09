#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &arr,int k){

  int n = arr.size();
  int left = 0;
  int right = n-1;

  while(left<=right){
    int mid = left + (right-left)/2;

    if (arr[mid]==k){
      return arr[mid];
    }
    else if(arr[mid]>k){
      right = mid - 1;
    }
    else{
      left = mid + 1;
    }
  }

  if(right<0){
    return arr[left];
  }
  else if(left>=n){
    return arr[right];
  }
  else{
    if(abs(k-arr[right]) <= abs(k-arr[left])){
      return arr[right];
    }
    else{
      return arr[left];
    }
  }
  return {};
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

  cout<<search(arr,k);
  return 0;
}


