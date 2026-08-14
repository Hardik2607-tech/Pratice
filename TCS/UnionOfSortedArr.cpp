#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin>>n;

  vector<int>arr1(n);

  for(int i=0;i<n;i++){
    cin>>arr1[i];
  }

  int m;
  cin>>m;
  vector<int>arr2(m);

  for(int i=0;i<n;i++){
    cin>>arr2[i];
  }
  
  int i=0;
  int j=0;
  int last = -1;

  cout<<endl;
  while(i<n && j<m){
    if(arr1[i]<arr2[j]){
      if(arr1[i] != last) {
        cout << arr1[i] << " ";
        last = arr1[i];
      }
      i++;
    }
    else if(arr2[i]<arr1[i]){
      if(arr2[i] != last){
        cout<<arr2[i]<<" ";
        last = arr2[i];
      }
      j++;
    }
    else{
      if(arr1[i] != last) {
        cout << arr1[i] << " ";
        last = arr1[i];
      }
      i++;
      j++;
    }
  }


  while(i < n) {
    if(arr1[i] != last) {
      cout << arr1[i] << " ";
      last = arr1[i];
    }
    i++;
  }

  while(j < m) {
    if(arr2[j] != last) {
      cout << arr2[j] << " ";
      last = arr2[j];
    }
    j++;
  }

  return 0;
}
