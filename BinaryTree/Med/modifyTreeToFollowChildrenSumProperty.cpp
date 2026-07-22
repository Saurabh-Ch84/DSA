#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    bool isLeaf(TreeNode *root){
        return root and !root->left and !root->right;
    }
        public:
    bool checkIfChildSumPropertyHolds(TreeNode * root){
        if(!root || isLeaf(root)) return true;

        bool left=checkIfChildSumPropertyHolds(root->left);
        if(!left) return false;
        int leftVal=(root->left)?root->left->val:0;

        bool right=checkIfChildSumPropertyHolds(root->right);
        if(!right) return false;
        int rightVal=(root->right)?root->right->val:0;

        return root->val==leftVal+rightVal;
    }

    void changeTree(TreeNode *root){
        if(!root or isLeaf(root)) return ;

        int leftVal=(root->left)?root->left->val:0;
        int rightVal=(root->right)?root->right->val:0;
        if(root->val > leftVal + rightVal)
        {
            if(root->left) root->left->val=root->val;
            if(root->right) root->right->val=root->val;
        }

        changeTree(root->left);
        changeTree(root->right);

        leftVal=(root->left)?root->left->val:0;
        rightVal=(root->right)?root->right->val:0;

        root->val=leftVal+rightVal;
    }

    void inorder(TreeNode *root){
        if(!root) return ;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
};

int main(){
    TreeNode* root=new TreeNode(50);
    root->left=new TreeNode(7);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(1);
    root->right->right=new TreeNode(30);

    Solution s;
    s.inorder(root);
    cout<<endl;
    cout<<s.checkIfChildSumPropertyHolds(root)<<endl;
    s.changeTree(root);
    s.inorder(root);
    cout<<endl;
    cout<<s.checkIfChildSumPropertyHolds(root)<<endl;
return 0;
}