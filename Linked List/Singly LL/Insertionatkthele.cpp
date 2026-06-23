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

Node* insertatkthele(Node* head,int el,int k){
  if(head ==NULL){
    return new Node(el);
  }
  if(k==1){
    return new Node(el,head);
  }
  int cnt= 0;
  Node* temp = head;
  while(temp != NULL){
    cnt++;
    if(cnt == (k-1)){
      Node* x = new Node(el,temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}

int main(){

  vector<int> arr;
  arr = {12,46,35,57,16,24,35,56};
  Node* head = convertarrtoll(arr);

  int el;
  cin>>el;
   
  int k;
  cin>>k;

  head = insertatkthele(head,el,k);

  print(head);
  return 0;
}