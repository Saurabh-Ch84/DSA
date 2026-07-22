#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//striver's approach morris traversal
class Solution3 {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* prev=curr->left;
                while(prev->right) prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};

//Striver's approaches
class Solution1 {
    void revPostOrder(TreeNode* root,TreeNode* &prev){
        if(!root) return ;
        revPostOrder(root->right,prev);
        revPostOrder(root->left,prev);
        root->left=nullptr;
        root->right=prev;
        prev=root;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prev=nullptr;
        revPostOrder(root,prev);
    }
};

class Solution2 {
public:
    void flatten(TreeNode* root) {
        if(!root) return ;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
            if(!s.empty())
                node->right=s.top();
            node->left=nullptr;
        }
    }
};

int main(){

return 0;
}