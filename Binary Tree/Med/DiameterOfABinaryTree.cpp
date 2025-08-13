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

class Solution {
    int DFS(TreeNode* root,int &maxHeight){
        if(!root) return 0;
        int leftHeight=DFS(root->left,maxHeight);
        int rightHeight=DFS(root->right,maxHeight);
        maxHeight=max(maxHeight,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxHeight=0;
        DFS(root,maxHeight);
        return maxHeight;
    }
};

int main(){

return 0;
}