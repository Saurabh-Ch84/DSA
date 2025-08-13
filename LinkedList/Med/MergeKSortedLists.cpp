#include<iostream>
#include<queue>
using namespace std;

// Linked list Node structure

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
    struct Comp{
        bool operator()(const Node* a,const Node *b)const{
            return a->data > b->data;
        }
    };
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*,vector<Node*>,Comp> minHeap;
        for(Node *node:arr)
            minHeap.push(node);
            
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        while(!minHeap.empty()){
            Node *minNode=minHeap.top();
            minHeap.pop();
            Node *nextNode=minNode->next;
            if(nextNode) minHeap.push(nextNode);
            temp->next=minNode;
            temp=temp->next;
        }
        return dummy->next;
    }
};

int main(){

return 0;
}