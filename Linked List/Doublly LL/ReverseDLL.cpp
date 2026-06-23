#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
  int data;
  Node* next;
  Node* back;

  Node(int data){
    this->data = data;
    next = nullptr;
    back = nullptr;
  }

  Node(int data1,Node* next1,Node* back1){
    data = data1;
    next = next1;
    back = back1;
  }
};

Node* convertarrtodll(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* prev = head;
  int n = arr.size();

  for(int i=1;i<n;i++){
    Node* temp = new Node(arr[i],nullptr,prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

Node* reversedll(Node* head){
  Node* prev = NULL;
  Node* cur = head;

  while (cur!= NULL){
    Node* nextnode = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nextnode;
  }
  return prev;
}

int main(){

  vector<int>arr;

  arr = {12,46,39,57,16,24,35,56};
  Node* head = convertarrtodll(arr);

  

  head = reversedll(head);

  print(head);

  return 0;
}