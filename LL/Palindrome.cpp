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


Node* reversell(Node* head){

  Node* prev = NULL;
  Node* cur = head;
  
  while (cur != NULL){
    Node* next = cur->next;
    cur->next = prev;

    prev = cur;
    cur = next;
  }
  return prev;
}

bool isPalindrome(Node* head){
  if (head == NULL || head->next == NULL){
    return true;
  }

  Node* slow = head;
  Node* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  Node* secondHalf = reversell(slow);
  Node* firstHalf = head;

  while (secondHalf != NULL) {
    if (firstHalf->data != secondHalf->data){
      return false;
    }
    firstHalf = firstHalf->next;
    secondHalf = secondHalf->next;
  }
  return true;
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

  if(isPalindrome(head)){
    cout<<"True"<<endl;
  }
  else{
    cout<<"False"<<endl;
  }

  return 0;
}