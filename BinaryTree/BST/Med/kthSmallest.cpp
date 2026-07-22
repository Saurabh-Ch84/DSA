#include<iostream>
#include<stack>
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
    class BST_iterator{
        stack<TreeNode*> s;
        void recursion(TreeNode* root){
            if(!root) return ;
            s.push(root);
            recursion(root->left);
        }
            public:
        BST_iterator(TreeNode* root){
            recursion(root);
        }
        TreeNode* next(){
            if(s.empty()) return nullptr;
            TreeNode* node=s.top();s.pop();
            recursion(node->right);
            return node;
        }
    };
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        BST_iterator bstItr(root);
        while(k>1){
            bstItr.next();
            k--;
        }
        return bstItr.next()->val;
    }
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