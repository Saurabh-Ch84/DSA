#include<iostream>
using namespace std;

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode *prev=nullptr,*curr=head;
        while(curr){
            curr->prev=curr->next;
            curr->next=prev;
            prev=curr;
            curr=curr->prev;
        }
        return prev;
    }
};

int main(){

return 0;
}