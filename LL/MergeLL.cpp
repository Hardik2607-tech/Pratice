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

Node* mergeLL(Node* head1, Node* head2){
  Node* dummy = new Node(0);
  Node* tail = dummy;

  while(head1 && head2){ 
    if(head1->data < head2->data){
      tail->next = head1;
      head1 = head1->next;
    }
    else{
      tail->next = head2;
      head2 = head2->next;
    }
    tail = tail->next;
  }

  if (head1){
    tail->next = head1;
  }
  else{
    tail->next = head2;
  }

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

  cout<<endl;
  int n;
  cin>>n;

  vector<int>arr1(n);

  for(int i=0;i<n;i++){
    cin>>arr1[i];
  }

  cout<<endl;
  int m;
  cin>>m;

  vector<int>arr2(m);

  for(int i=0;i<m;i++){
    cin>>arr2[i];
  }
  
  Node* head1 = arrtoll(arr1);
  Node* head2 = arrtoll(arr2);
  
  Node* Merge = mergeLL(head1,head2);
  
  cout<<endl;
  printLL(Merge);

  cout<<endl;
  return 0;
}