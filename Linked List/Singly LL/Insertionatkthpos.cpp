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

  Node(int data, Node* next1) {
    this->data = data;
    next = next1;
  }
};

Node* convertarrtoll(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  int n = arr.size();

  for(int i=1;i<n;i++){
    Node* temp = new Node(arr[i]);
    mover-> next = temp;
    mover = temp;
  }
  return head;
}

void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
}

Node* insertatkthpos(Node* head,int el){
  
}

int main(){

  vector<int> arr;
  arr = {12,46,35,57,16,24,35,56};
  Node* head = convertarrtoll(arr);

  int el;
  cin>>el;

  head = insertatkthpos(head,el);

  print(head);
  return 0;
}