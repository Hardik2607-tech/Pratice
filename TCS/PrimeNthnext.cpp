#include<iostream>
using namespace std;

bool is_primeNo(int n){

  if(n<2) return false;

  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  cin>>n;

  int s;
  cin>>s;

  int cnt = 0;
  int nth = 0;
  int i = s;

  while(cnt<n){
    if(is_primeNo(i)){
      cnt++;

      if(cnt==n){
        nth = i;
        break;
      }
    }
    i++;
  }

  int sum = nth;// Adding the cal nth prime no.
  int found = 0;
  int nextnth = nth+1; // Now moving to next two no.

  while(found<2){

    if(is_primeNo(nextnth)){
      sum += nextnth;
      found++;
    }
    nextnth++;
  }

  cout<<endl<<sum<<endl;
  return 0;
}