#include<bits/stdc++.h>
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
    bool isValidBST(TreeNode* root,long long mini,long long maxi){
        if(!root) return 1;
        int curr=root->val;
        if(curr<=mini || curr>=maxi) return 0;
        return (isValidBST(root->left,mini,1LL*curr) && isValidBST(root->right,1LL*curr,maxi));
    }
public:
    bool isValidBST(TreeNode* root) {
        long long mini=-1e12, maxi=1e12;
        return isValidBST(root,mini,maxi);
    }
};

int main(){

return 0;
}