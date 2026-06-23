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

Node* insertattail(Node* head,int val,int k){
  if (k == 1) {
    Node* newNode = new Node(val, head, nullptr);
    if(head){
      head->back = newNode;
    }
    return newNode;
  }

  Node* temp = head;
  int cnt = 1;

  while (temp != NULL && cnt < k - 1) {
    temp = temp->next;
    cnt++;
  }

  if (temp == NULL) return head;

  Node* newNode = new Node(val, temp->next, temp);

  if (temp->next != NULL) {
    temp->next->back = newNode;
  }

  temp->next = newNode;

  return head;
}

int main(){

  vector<int>arr;

  arr = {12,46,39,57,16,24,35,56};
  Node* head = convertarrtodll(arr);

  int val;
  cin>>val;

  int k;
  cin>>k;

  head = insertattail(head,val,k);

  print(head);

  return 0;
}