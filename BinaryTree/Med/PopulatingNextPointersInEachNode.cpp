#include<iostream>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root || (!root->left && !root->right)) 
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            Node* prev=nullptr;
            for(int i=0;i<sz;i++){
                Node* node=q.front();
                q.pop();
                if(node->right){
                    q.push(node->right);
                    node->right->next=prev;
                    prev=node->right;
                }
                if(node->left){
                    q.push(node->left);
                    node->left->next=prev;
                    prev=node->left;
                }
            }
        }
        return root;
    }
};

int main(){

return 0;
}