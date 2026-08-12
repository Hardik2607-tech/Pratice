#include<iostream>
using namespace std;

int main(){

  string day;
  cin>>day;

  int n;
  cin>>n;

  int m=0;

  int ans=0;

  if(day=="mon") m=6;
  else if(day=="tue") m=5;
  else if(day=="wed") m=4;
  else if(day=="thu") m=3;
  else if(day=="fri") m=2;
  else if(day=="sat") m=1;
  else if(day=="sun") m=0;
  else  cout<<"invalid";
  
  if(n-m>=1){
    ans = 1 + (n - m)/7;
  }

  cout<<ans;
  return 0;
} 


