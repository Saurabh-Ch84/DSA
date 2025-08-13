#include<iostream>
#include<vector>
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
public:
    bool getPath(TreeNode *root, vector<int> &arr, int x) {
        if (!root) return false;
        arr.push_back(root->val);
        if (root->val == x || getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;
        arr.pop_back();
        return false;
    }
public:
    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        if (!A) return arr;
        getPath(A, arr, B);
        return arr;
    }
};

int main(){

return 0;
}