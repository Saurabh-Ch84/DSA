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
    class BST_Iterator{
        stack<TreeNode*> st;
        void insert(TreeNode* root){
            while(root){
                st.push(root);
                root=root->left;
            }
        }
            public:
        BST_Iterator(TreeNode* root){
            insert(root);
        }
        bool isEmpty(){
            return st.empty();
        }
        int peek(){
            TreeNode* smallest=st.top();
            return smallest->val;
        }
        void pop(){
            TreeNode* smallest=st.top();
            st.pop();
            insert(smallest->right);
        }
    };
public:
    vector<int> findMode(TreeNode* root) {
        BST_Iterator bstItr(root);
        vector<int> res;
        int maxFreq=0;
        while(!bstItr.isEmpty()){
            int currVal=bstItr.peek(), freq=0;
            while(!bstItr.isEmpty() && bstItr.peek()==currVal){
                freq++;
                bstItr.pop();
            }
            if(freq<maxFreq) continue;
            if(freq>maxFreq) res.clear();
            res.push_back(currVal);
            maxFreq=max(maxFreq,freq);
        }
        return res;
    }
};

int main(){

return 0;
}