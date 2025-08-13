#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(!head || !head->next) return head;
        Node *left=head,*right=head->next;
        while(right){
            while(right && left->data==right->data)
            {
                Node *nextNode=right->next;
                right->prev=nullptr;
                right->next=nullptr;
                delete right;
                right=nextNode;
            }
            left->next=right;
            if(right){
                right->prev=left;
                left=right;
                right=right->next;
            }
        }
        if(left) left->next = nullptr;
        return head;
    }
};

int main(){

return 0;
}