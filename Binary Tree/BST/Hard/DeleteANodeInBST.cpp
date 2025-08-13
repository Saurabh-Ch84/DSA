#include <iostream>
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

class Solution
{
    TreeNode *helper(TreeNode *node)
    {
        if (!node->left)
            return node->right;
        if (!node->right)
            return node->left;
        TreeNode *leftSubtree = node->left;
        TreeNode *lastRight = leftSubtree;
        while (lastRight->right)
            lastRight = lastRight->right;
        lastRight->right = node->right;
        return leftSubtree;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (root->val == key)
        {
            TreeNode *newRoot = helper(root);
            root->left = root->right = nullptr;
            delete root;
            return newRoot;
        }
        TreeNode *curr = root;
        while (curr)
        {
            if (key < curr->val)
            {
                if (curr->left && curr->left->val == key)
                {
                    TreeNode *temp = curr->left;
                    curr->left = helper(curr->left);
                    temp->left = temp->right = nullptr;
                    delete temp;
                    break;
                }
                curr = curr->left;
            }
            else
            {
                if (curr->right && curr->right->val == key)
                {
                    TreeNode *temp = curr->right;
                    curr->right = helper(curr->right);
                    temp->left = temp->right = nullptr;
                    delete temp;
                    break;
                }
                curr = curr->right;
            }
        }
        return root;
    }
};

int main()
{

    return 0;
}