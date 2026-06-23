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
  Node* head = new Node(arr[0]);
  Node* mover = head;
  int n = arr.size();

  for(int i=1;i<n;i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}


void printll(Node * head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
}

Node* reversell(Node* head){
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

  vector<int> arr;

  arr = {12,46,35,57,16,24,35,56};

  Node* head = convertarrtoll(arr);

  cout<<"Before Reversing: ";
  printll(head);

  head = reversell(head);

  cout<<endl<<"After Reversing: ";
  printll(head);
  return 0;
}
