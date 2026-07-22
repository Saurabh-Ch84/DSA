#include<iostream>
#include<stack>
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

//optimal
class Solution1 {
    bool isTreeSame(Node *r1,Node *r2){
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        if(r1->data!=r2->data) return false;
        return isTreeSame(r1->left,r2->right) 
                && 
                isTreeSame(r1->right,r2->left);
    }
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if(!root) return true;
        return isTreeSame(root->left,root->right);
    }
};

//weird non-efficient overkill
class Solution2 {
    void DFS1(TreeNode *root,stack<pair<TreeNode*,int>> &s,int level=-1){
        if(!root) return ;
        DFS1(root->left,s,level-1);
        DFS1(root->right,s,level+1);
        s.push({root,level});
        //postOrder
    }
    
    bool DFS2(TreeNode *root,stack<pair<TreeNode*,int>> &s,int level=1){
        if(!root) return true;
        if(s.empty() || level+s.top().second || root->val!=s.top().first->val) 
            return false;
        s.pop();
        return DFS2(root->left,s,level-1) && DFS2(root->right,s,level+1);
        //preOrder
    }
  public:
    bool isSymmetric(TreeNode* root) {
        // Code here
        if(!root) return true;
        stack<pair<TreeNode*,int>> s;
        DFS1(root->left,s);
        return DFS2(root->right,s) && s.empty();
    }
};


int main(){

return 0;
}