#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void update(TreeNode* curr,TreeNode* &prevNode,TreeNode* &firstNode,TreeNode* &secondNode){
        if(prevNode && prevNode->val > curr->val){
            if(!firstNode) firstNode=prevNode;
            secondNode=curr;
        }
        prevNode=curr;
    }
    
    void inorder(TreeNode* root,TreeNode* &prevNode,TreeNode* &firstNode,TreeNode* &secondNode){
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                update(curr,prevNode,firstNode,secondNode);
                curr=curr->right;
            }
            else{
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr)
                    pred=pred->right;
                if(pred->right){
                    pred->right=nullptr;
                    update(curr,prevNode,firstNode,secondNode);
                    curr=curr->right;
                }
                else{
                    pred->right=curr;
                    curr=curr->left;
                }
            }
        }
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