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

//BFS Better
class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        res.push_back(root->val);
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    flag=true;
                }
                if(node->right)
                {
                    q.push(node->right);
                    flag=true;
                }
            }
            if(flag) res.push_back(q.back()->val);
        }
        return res;
    }
};

int main(){

return 0;
}