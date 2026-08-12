#include<iostream>
using namespace std;
int main (){

  int n;
  cin >> n;
  
  int mask = 15;
  cout<<(n ^ mask)<<endl;

}