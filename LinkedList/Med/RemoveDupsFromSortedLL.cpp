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
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if(!head) return head;
        Node* prev=head;
        Node* curr=prev->next;
        
        while(curr){
            if(curr->data==prev->data){
                Node* temp=curr;
                curr=curr->next;
                temp->next=nullptr;
                delete temp;
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};

int main(){

return 0;
}