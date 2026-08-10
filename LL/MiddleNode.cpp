#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int val){
    data = val;
    next = NULL;
  }
};

Node* arrtoll(vector<int> &arr){

  int n = arr.size();
  Node* head = new Node(arr[0]);
  Node* temp = head;

  for(int i=1;i<n;i++){
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }
  return head;
}


Node* findMiddle(Node* head){

  Node* slow = head;
  Node* fast = head;

  while(fast != NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}


void printLL(Node* head) {

  Node* temp = head;

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int main(){

  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  Node* head = arrtoll(arr);

  Node* Middle = findMiddle(head);
  cout << Middle->data<<endl;

  return 0;
}