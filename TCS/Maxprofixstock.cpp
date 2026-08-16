#include<iostream>
#include<vector>
using namespace std;

int main(){

  int n;
  cin>>n;


  vector<int>price(n);

  for(int i=0;i<n;i++){
    cin>>price[i];
  }

  int minprice = price[0];
  int maxprofit = 0;

  for(int i=0;i<n;i++){
    int profit = price[i] - minprice;
    maxprofit = max(profit,maxprofit);
    minprice =  min(price[i],minprice);
  }

  cout<<maxprofit;

  return 0;
}