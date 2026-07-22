#include<iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Striver's approach  TC-O((logn)^2)
class Solution {
    int getLeftHeight(TreeNode* root){
        int height=0;
        while(root){
            root=root->left;
            height++;
        }
        return height;
    }

    int getRightHeight(TreeNode* root){
        int height=0;
        while(root){
            root=root->right;
            height++;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight=getLeftHeight(root);
        int rightHeight=getRightHeight(root);
        if(leftHeight==rightHeight) return (1<<leftHeight)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

int main(){

return 0;
}