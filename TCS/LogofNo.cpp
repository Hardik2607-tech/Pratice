#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  long long  k;
  cin>>k;

  long long  l;
  cin>>l;

  long long ans = 0;

  for(long long i=l;i<=k;i++){
    ans += log2(i);
  }

  cout<<endl<<ans<<endl;
  return 0;
}


