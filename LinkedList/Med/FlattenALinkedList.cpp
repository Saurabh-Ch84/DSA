#include<iostream>
#include<queue>
using namespace std;

// Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

class Solution {
    struct Comp {
        bool operator()(const Node* a, const Node* b) const {
            return a->data > b->data;  // min-heap: smallest data at top
        }
    };

  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        Node *dummy=new Node(-1),*temp=root;
        priority_queue<Node*,vector<Node*>,Comp> minHeap;
        while(temp){
            minHeap.push(temp);
            temp=temp->next;
        }
        temp=dummy;
        while(!minHeap.empty()){
            Node *minNode=minHeap.top();
            minHeap.pop();
            Node *nextNode=minNode->bottom;
            if(nextNode) minHeap.push(nextNode);
            temp->bottom=minNode;
            temp=temp->bottom;
        }
        return dummy->bottom;
    }
};

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        Node *dummy=new Node(-1),*temp=root;
        priority_queue<pair<int,Node*>,
                    vector<pair<int,Node*>>,
                    greater<pair<int,Node*>>> minHeap;
        while(temp){
            minHeap.push({temp->data,temp});
            temp=temp->next;
        }
        temp=dummy;
        while(!minHeap.empty()){
            Node *minNode=minHeap.top().second;
            minHeap.pop();
            Node *nextNode=minNode->bottom;
            if(nextNode) minHeap.push({nextNode->data,nextNode});
            temp->bottom=minNode;
            temp=temp->bottom;
        }
        return dummy->bottom;
    }
};

int main(){

return 0;
}