#include<iostream>
using namespace std;

//Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        struct Node *prev=nullptr,*curr=head,*front=head;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
};

int main(){

return 0;
}