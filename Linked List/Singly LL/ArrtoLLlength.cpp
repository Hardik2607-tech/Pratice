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

Node* convertarrtoll(vector<int>&arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  int n = arr.size();

  for(int i=1;i<n;i++){
    Node* temp = new Node(arr[i]);
    mover-> next = temp;
    mover = temp;
  }
  return head;
}

int  lengthofll(Node* head){
  int cnt = 0;
  Node*temp = head;
  while (temp){
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

int main(){
  vector<int>arr;

  arr = {12,3,5,8};
  Node* head = convertarrtoll(arr);
  cout<< lengthofll(head);

  return 0;
}