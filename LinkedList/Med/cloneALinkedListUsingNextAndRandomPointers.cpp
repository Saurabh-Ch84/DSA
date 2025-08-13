#include<iostream>
#include<vector>
#include<unordered_map>
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

//optimal in space
class Solution1 {
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

//better in space
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hashMap;
        hashMap[nullptr]=nullptr;
        Node *dummy=new Node(-1);
        Node *temp=dummy,*mover=head;
        while(mover){
            int data=mover->val;
            Node *newNode=new Node(data);
            hashMap[mover]=newNode;
            temp->next=newNode;
            temp=temp->next;
            mover=mover->next;
        }
        temp=dummy->next;
        mover=head;
        while(mover){
            Node *orignalRandom=mover->random;
            Node *newRandom=hashMap[orignalRandom];
            temp->random=newRandom;
            temp=temp->next;
            mover=mover->next;
        }
        return dummy->next;
    }
};

//brute in terms of space
class Solution3 {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> array;
        unordered_map<Node*,Node*> hashMap;
        hashMap[nullptr]=nullptr;
        Node *dummy=new Node(-1);
        Node *temp=dummy,*mover=head;
        while(mover){
            int data=mover->val;
            Node *randomPtr=mover->random;
            array.push_back(randomPtr);
            Node *newNode=new Node(data);
            hashMap[mover]=newNode;
            temp->next=newNode;
            temp=temp->next;
            mover=mover->next;
        }
        temp=dummy->next;
        for(Node *node:array){
            temp->random=hashMap[node];
            temp=temp->next;
        }
        return dummy->next;
    }
};

int main(){

return 0;
}