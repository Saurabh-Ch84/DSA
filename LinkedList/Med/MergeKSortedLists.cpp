#include<iostream>
#include<queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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

 
class Solution {
    struct Comp{
        bool operator()(const ListNode* a,const ListNode* b) const{
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Comp> pq;
        for(ListNode *node:lists)
            if(node) pq.push(node);

        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(!pq.empty()){
            ListNode* node=pq.top();pq.pop();
            curr->next=node;
            curr=curr->next;
            if(node->next){
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};

int main(){

return 0;
}