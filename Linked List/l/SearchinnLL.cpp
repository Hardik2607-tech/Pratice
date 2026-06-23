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

int searchoffele(Node* head,int val ){
  Node* temp = head;
  while(temp != NULL){
    if (temp->data == val) return 1;
    temp = temp -> next;
  }
  return 0;
}
int main(){
  vector<int> arr = {12,332,34,45,56};
  Node* head = convert2arr(arr);
  Node* temp = head;
  cout<<searchoffele(head,12);
  return 0;
} 