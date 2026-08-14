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

  int cursum = arr[0];
  int maxsum = arr[0];

  for(int i=1;i<n;i++){
    cursum = max(cursum+arr[i],arr[i]);
    maxsum = max(maxsum,cursum);
  }

  cout<<maxsum<<endl;

  return 0;
}