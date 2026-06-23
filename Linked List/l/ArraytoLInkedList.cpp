#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert2arr(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1;i<arr.size();i++){
    Node* temp = new Node(arr[i]);
    mover-> next = temp;
    mover = temp;
  }
  return head;
}

int lengthofll(Node* head){
  int cnt = 0;
  Node* temp = head;
  while(temp != NULL){
    temp = temp->next;
    cnt++;
  }
  return cnt;
}
int main(){
  vector<int> arr = {12,332,34,45,56};
  Node* head = convert2arr(arr);
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
  cout<<lengthofll(head);
  return 0;
} 