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

void print(Node* head){
  while (head != NULL){
    cout<<head->data<<" ";
    head = head->next;
    }
  cout<<endl;
}

Node* removehead(Node* head){
  if(head==NULL) return head;
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}

int main(){
  vector<int> arr;

  arr = {12,46,35,57,16,24,35,56};

  Node* head = convertarrtoll(arr);
  head = removehead(head);

  print(head);

  return 0;
}