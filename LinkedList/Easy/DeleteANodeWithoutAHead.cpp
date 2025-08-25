#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    void deleteNode(Node* del_node) {
        // code here
        Node* next_node=del_node->next;
        del_node->data=next_node->data;
        del_node->next=next_node->next;
        next_node->next=nullptr;
        delete next_node;
    }
};

int main(){

return 0;
}