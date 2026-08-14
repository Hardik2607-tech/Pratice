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

  int k;
  cin>>k;

// 1. Reverse entire array
  int start = 0;
  int end = n - 1;

  while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
  }

  k = k % n;  

// 2. Reverse first k elements
  start = 0;
  end = k - 1;

  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }

// 3. Reverse end k elements
  start = k;
  end = n - 1;

  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }

  
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
