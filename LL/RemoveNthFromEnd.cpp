#include<iostream>
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

Node* removeNthFromEnd(Node* head, int k){
  Node* dummy = new Node(0);
  dummy->next = head;
  Node* slow = dummy;
  Node* fast = dummy;

  for(int i=0;i<k;i++){
    fast = fast->next;
  }
  
  while(fast->next!=NULL){
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = slow->next->next;

  return dummy->next;
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

  int k;
  cin>>k;
  
  Node* head = arrtoll(arr);

  head = removeNthFromEnd(head,k);

  printLL(head);
  return 0;
}