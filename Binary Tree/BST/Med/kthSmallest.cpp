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
    int getKthSmallest(TreeNode *root,int &k){
        if(!root) return -1;
        int leftAns=getKthSmallest(root->left,k);
        if(leftAns!=-1) return leftAns;
        if(--k==0) return root->val;
        return getKthSmallest(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int k_=k;
        return getKthSmallest(root,k_);
    }
};

int main(){

return 0;
}