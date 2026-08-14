#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int m;
  cin>>m;

  vector<vector<int>>matrix(n,vector<int>(m,0));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>matrix[i][j];
    }
  }

  for(int i=0;i<m;i++){
    for(int j=i+1;j<n;j++){
      swap(matrix[i][j],matrix[j][i]);
    }
  }

  for(int i=0;i<n;i++){
    reverse(matrix[i].begin(),matrix[i].end());
  }

  cout<<endl;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}