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

  int dup = 0;
  int miss = 0;
  int exp = n * (n + 1)/2;
  int cal = 0;

  for(int i=0;i<n-1;i++){
    cal += arr[i];
  }

  for(int i=0;i<n;i++){
    if(arr[i]==arr[i+1]){
      dup = arr[i];
    }
  }
  miss = cal - exp;

  cout<<miss<<endl;
  cout<<dup<<endl;

  return 0;
}
