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

Node* deletekthele(Node* head,int el){
  if(head==NULL) return head;

  if(head->data==el){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  Node* temp = head;
  Node* prev = NULL;

  while(temp != NULL) {
    if(temp->data == el) {
      prev->next = temp->next;
      delete temp;
      break;  
    }
    prev = temp;
    temp = temp->next;
  }

  return head;
}

int main(){

  vector<int>arr;

  arr = {12,46,39,57,16,24,35,56};
  Node* head = convertarrtodll(arr);

  int el;
  cin>>el;

  head = deletekthele(head,el);

  print(head);

  return 0;
}