#include<bits/stdc++.h>
using namespace std;

// Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
    Node* recursion(Node *node, Node* prev){
        if(!node) return nullptr;
        Node* nextNode=recursion(node->next,node);
        if(!nextNode || node->data>=nextNode->data)
            return node;
        else{
            if(prev) prev->next=nextNode;
            node->next=nullptr;
            delete node;
            return nextNode;
        }
    }
  public:
    Node *compute(Node *head) {
        // code here
        return recursion(head,nullptr);
    }
};

int main(){

return 0;
}