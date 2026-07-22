#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void inorder(TreeNode* curr,TreeNode* &prev,TreeNode* &first,TreeNode* &second){
        if(!curr) return ;
        inorder(curr->left,prev,first,second);
        if(prev && prev->val>curr->val){
            if(!first) first=prev;
            second=curr;
        }
        prev=curr;
        inorder(curr->right,prev,first,second);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev=nullptr;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        inorder(root,prev,first,second);
        if(first && second) swap(first->val,second->val);
    }
};

int main(){

return 0;
}