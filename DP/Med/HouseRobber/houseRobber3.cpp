#include <iostream>
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

class Solution
{
    pair<int, int> DFS(TreeNode *root)
    {
        if (!root->left && !root->right)
            return {0, root->val}; //first-- if you don't rob , second-- if you rob this node
        pair<int, int> p;
        p = {0, root->val};
        if (root->left)
        {
            pair<int, int> temp1 = DFS(root->left);
            p.first += max(temp1.second, temp1.first);
            p.second += temp1.first;
        }
        if (root->right)
        {
            pair<int, int> temp2 = DFS(root->right);
            p.first += max(temp2.second, temp2.first);
            p.second += temp2.first;
        }
        return p;
    }

public:
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;
        pair<int, int> answer;
        answer = DFS(root);
        return max(answer.first, answer.second);
    }
};

int main()
{

    return 0;
}