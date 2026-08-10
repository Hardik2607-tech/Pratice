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

bool cycleDet(Node* head){

  Node* slow = head;
  Node* fast = head;

  while(fast && fast->next!= NULL){
    slow = slow->next;
    fast = fast->next->next;
    
    if(slow == fast){
      return true;
    }
  }
  return false;
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

  // Creating cycle
  Node* temp = head;
  Node* cycleNode = head->next->next; 

    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = cycleNode;

  if (cycleDet(head))
    cout<< endl << "Cycle exists"<< endl;
  else
    cout<< endl << "No cycle"<< endl;

  return 0;
}