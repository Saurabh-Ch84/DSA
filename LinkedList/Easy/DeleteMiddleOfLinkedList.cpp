#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    Node* deleteMid(Node* head) {
        // Your Code Here
        Node *fast=head,*slow=head;
        Node *prev=nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(!prev){
            delete head;
            return nullptr;
        }
        prev->next=slow->next;
        slow->next=nullptr;
        delete slow;
        return head;
    }
};

int main(){

return 0;
}