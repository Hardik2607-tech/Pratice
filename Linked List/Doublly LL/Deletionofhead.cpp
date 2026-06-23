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

Node* deletehead(Node* head){
  if(head==NULL) return head;

  Node* prev = head;
  head = head->next;
  head -> back = nullptr;
  prev -> next = nullptr;
  
  delete(prev);
  return head;
}

int main(){

  vector<int>arr;

  arr = {12,46,35,57,16,24,35,56};
  Node* head = convertarrtodll(arr);
  head = deletehead(head);

  print(head);

  return 0;
}