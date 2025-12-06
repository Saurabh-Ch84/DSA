#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *mover=head;
        while(mover){
            int data=mover->val;
            Node *newNode=new Node(data);
            newNode->next=mover->next;
            mover->next=newNode;
            mover=mover->next->next;
        }
        mover=head;
        while(mover){
            Node *origRandom=mover->random;
            Node *newRandom=(origRandom)?origRandom->next:origRandom;
            mover->next->random=newRandom;
            mover=mover->next->next;
        }

        Node *dummy=new Node(-1);
        mover=head;
        Node *temp=dummy;
        while(mover){
            temp->next=mover->next;
            mover->next=mover->next->next;
            temp=temp->next;
            mover=mover->next;
        }
        return dummy->next;
    }
};

int main(){

return 0;
}