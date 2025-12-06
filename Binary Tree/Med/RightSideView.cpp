#include<iostream>
#include<vector>
#include<queue>
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


struct Node
{
    int data;
    Node* left;
    Node* right;
};

//DFS optimal
class Solution1 {
    void DFS(Node *root,vector<int> &ds,int level=0){
        if(!root) return ;
        if(level==ds.size()) ds.push_back(root->data);
        DFS(root->right,ds,level+1);
        DFS(root->left,ds,level+1);
    }
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> right;
        DFS(root,right);
        return right;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;

        while(!q.empty()){
            TreeNode* node_=q.back();
            ans.push_back(node_->val);
            int sz=q.size();
            while(sz){
                TreeNode* node=q.front();q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                sz--;
            }
        }
        return ans;
    }
};

int main(){

return 0;
}