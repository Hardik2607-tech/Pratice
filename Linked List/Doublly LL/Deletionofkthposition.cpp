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

Node* deletekthpos(Node* head,int idx){
  if(head==NULL) return head;

  if(idx==1){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  Node* temp = head;
  Node* prev = NULL;
  int cnt = 1;

  while(temp != NULL && cnt < idx) {
    prev = temp;
    temp = temp->next;
    cnt++;
  }
  if(temp == NULL) return head;
    prev->next = temp->next;
  delete temp;

  return head;
}

int main(){

  vector<int>arr;

  arr = {12,46,39,57,16,24,35,56};
  Node* head = convertarrtodll(arr);

  int idx;
  cin>>idx;

  head = deletekthpos(head,idx);

  print(head);

  return 0;
}