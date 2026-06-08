#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> hashMap;
        unordered_set<int> childSet;
        for (auto &desc : descriptions)
        {
            int parent = desc[0], child = desc[1];
            if (!hashMap.count(parent))
            {
                TreeNode *p = new TreeNode(parent);
                hashMap[parent] = p;
            }
            if (!hashMap.count(child))
            {
                TreeNode *c = new TreeNode(child);
                hashMap[child] = c;
            }
            childSet.insert(child);
            if (desc[2])
                hashMap[parent]->left = hashMap[child];
            else
                hashMap[parent]->right = hashMap[child];
        }
        for (auto &p : hashMap)
        {
            if (!childSet.count(p.first))
                return p.second;
        }
        return nullptr;
    }
};

int main()
{

    return 0;
}