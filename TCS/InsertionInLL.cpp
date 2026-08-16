#include<iostream>
#include<vector>
using namespace std;

class  Node{
public:
  int data;
  Node* next;
  Node(int val){
    data = val;
    next = NULL;
  }
};



int main(){

  int n;
  cin>>n;


  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }


  return 0;
}