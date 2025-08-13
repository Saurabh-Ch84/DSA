#include<iostream>
#include<stack>
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


class BSTIterator {
    stack<TreeNode*> s;
    void insertion(TreeNode* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        insertion(root);
    }
    
    int next() {
        if(s.empty()) return -1;
        TreeNode* node=s.top();
        s.pop();
        int val=node->val;
        node=node->right;
        insertion(node);
        return val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

int main(){

return 0;
}