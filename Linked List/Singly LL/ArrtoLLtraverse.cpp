#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
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
      mover->next = temp;
      mover = temp;
    }
    return head;
}

int main(){
  vector<int>arr;

  arr = {2,5,8,7};
  Node* head = convertarrtoll(arr);
  Node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp= temp->next;
  }
  return 0;
}