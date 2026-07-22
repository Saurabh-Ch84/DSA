#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
    stack<Node*> inorderStack,revInorderStack;
    
    void pushLeft(Node* root){
        while(root){
            inorderStack.push(root);
            root=root->left;
        }
    }
    
    void pushRight(Node* root){
        while(root){
            revInorderStack.push(root);
            root=root->right;
        }
    }
    
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        pushLeft(root);
        pushRight(root);
        while(!inorderStack.empty() && !revInorderStack.empty()){
            Node* smallNode=inorderStack.top();
            Node* largeNode=revInorderStack.top();
            if(smallNode==largeNode) break;
            int sum=smallNode->data+largeNode->data;
            if(sum<target){
                inorderStack.pop();
                pushLeft(smallNode->right);
            }
            else if(sum>target){
                revInorderStack.pop();
                pushRight(largeNode->left);
            }
            else return true;
        }
        return false;
    }
};

int main(){

return 0;
}