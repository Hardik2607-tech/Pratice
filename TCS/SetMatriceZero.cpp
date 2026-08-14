#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin>>n;

  int m;
  cin>>m;

  vector<vector<int>>arr(n,vector<int>(m,0));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
    }
  }
  
  bool firstrowzero = false;
  bool firstcolzero = false;

  for(int j=0;j<m;j++){
    if(arr[0][j]== 0){
      firstrowzero = true;
      break;
    }
  }

  for(int i=0;i<n;i++){
    if(arr[i][0]==0){
      firstcolzero = true;
      break;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]==0){
        arr[i][0] = 0;
        arr[0][j] = 0;
      }
    }
  }

  for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
      if(arr[i][0] == 0 || arr[0][j] == 0){
        arr[i][j] = 0;
      }
    }
  }

  if(firstrowzero){
    for(int j=0;j<m;j++){
      arr[0][j] = 0;
    }
  }

  if(firstcolzero){
    for(int i=0;i<n;i++){
      arr[i][0] = 0;
    }
  }

  cout<<endl;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
