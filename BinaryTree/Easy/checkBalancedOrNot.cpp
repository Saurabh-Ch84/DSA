#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

using pib = pair<int,bool> ;

class Solution {
    pib DFS(TreeNode* root){
        if(!root) return {0,true};
        pib leftTree=DFS(root->left);
        pib rightTree=DFS(root->right);
        int height=max(leftTree.first,rightTree.first);
        int diff=abs(leftTree.first-rightTree.first);
        if(diff>1 || leftTree.second==false || rightTree.second==false) 
            return {1+height,false};
        return {1+height,true};
    }
public:
    bool isBalanced(TreeNode* root) {
        return DFS(root).second;
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