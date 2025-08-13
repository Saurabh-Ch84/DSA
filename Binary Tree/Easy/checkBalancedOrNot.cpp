#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    int DFS(Node *root){
        //base-case
        if(!root) return 0;

        //calculate left subtree
        int leftHeight=DFS(root->left);
        // unbalance in the left subtree
        if(leftHeight==-1) return -1;
        
        //calculate right subtree
        int rightHeight=DFS(root->right);
        //unbalance in the right subtree
        if(rightHeight==-1) return -1;

        // unbalance in this level
        if(abs(leftHeight-rightHeight)>1) return -1;

        // return height
        return 1+max(leftHeight,rightHeight);
    }
  public:
    bool isBalanced(Node* root) {
        // Code here
        return DFS(root)!=-1;
    }
};

int main(){

return 0;
}