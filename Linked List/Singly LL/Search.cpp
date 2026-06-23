#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    next = nullptr;
  }
};

Node* convertarrtoll(vector<int> &arr){
  Node* head = new Node(arr[0]);;
  Node* mover = head;
  int n = arr.size();

  for(int i=1;i<n;i++){
    Node* temp = new Node(arr[i]);
    mover-> next = temp;
    mover = temp;
  }
  return head;
}

int search(Node* head,int value){
  Node* temp = head;
  while (temp){
    if(temp->data==value){
      return 1;
    }
    temp = temp -> next;
  }
  return 0;
}


int main(){
  vector<int>arr;
  arr = {12,3,7,4,5};
  Node* head = convertarrtoll(arr);

  int value;
  cin>>value;

  cout<<search(head,value);

  return 0;
}