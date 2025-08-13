#include<iostream>
#include<vector>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//concept of threading
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> inorder;
        Node* curr=root;
        while(curr){
            if(!curr->left){
                inorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node *prev=curr->left;
                while(prev->right && prev->right!=curr)
                    prev=prev->right;
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    inorder.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preOrder(Node* root) {
        // Your code here
        vector<int> preorder;
        Node* curr=root;
        while(curr){
            if(!curr->left){
                preorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node *prev=curr->left;
                while(prev->right && prev->right!=curr)
                    prev=prev->right;
                if(!prev->right){
                    prev->right=curr;
                    preorder.push_back(curr->data);
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};

int main(){

return 0;
}