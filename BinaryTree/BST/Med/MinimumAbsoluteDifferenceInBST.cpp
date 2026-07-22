#include<iostream>
#include<vector>
#include<stack>
#include<climits>
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


class Solution{
    class BST_iterator{
        stack<TreeNode*> st;
        void helper(TreeNode* root){
            while(root){
                st.push(root);
                root=root->left;
            }
        }
            public:
        BST_iterator(TreeNode* root){
            helper(root);
        }   

        bool empty(){
            return st.empty();
        }

        int peek(){
            TreeNode* node=st.top();
            int val=node->val;
            st.pop();
            helper(node->right);
            return val;
        }
    };
public:
    int getMinimumDifference(TreeNode* root) {
        BST_iterator bstItr(root);
        int mini=INT_MAX, prev=-1;
        while(!bstItr.empty()){
            int curr=bstItr.peek();
            if(prev!=-1) mini=min(mini,curr-prev);
            prev=curr;
        }
        return mini;
    }
};

int main(){

return 0;
}