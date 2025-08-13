#include<iostream>
using namespace std;


//The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
    Node* reverse(Node* root){
        Node* prev=nullptr;
        Node* curr=root;
        Node* front=root;
        while(front){
            front=front->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
  public:
    Node *inPlace(Node *root) {
        if(!root || !root->next) return root;
        // Code here
        Node* fast=root;
        Node* slow=root;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* right=reverse(slow->next);
        slow->next=nullptr;
        Node* left=root;
        
        while(right){
            Node* tempRight=right->next;
            right->next=left->next;
            left->next=right;
            right=tempRight;
            left=left->next->next;
        }
        return root;
    }
};

int main(){

return 0;
}