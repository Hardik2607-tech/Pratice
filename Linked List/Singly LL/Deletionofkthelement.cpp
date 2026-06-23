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
  while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}

Node* removeEl(Node*head,int el){
  if(head==NULL) return  head;

  if(head->data==el){
    Node* temp = head;
    head = head->next;
    delete(temp);
    return head; 
  }
  Node* temp = head;
  Node* prev = NULL;
  while(temp != NULL){
    if(temp->data==el){
      prev->next = prev->next->next;
      delete(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}


int main(){

  vector<int>arr;

  arr = {12,46,35,57,16,24,35,56};

  Node* head = convertarrtoll(arr);

  int el;
  cin>>el;

  head = removeEl(head,el);
  print(head);
  return 0;

}