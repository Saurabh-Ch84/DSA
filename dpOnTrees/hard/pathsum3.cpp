#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution_PathSum {
private:
    int count = 0;
    int target;
    unordered_map<long long, int> prefixSumMap;

    void dfs(TreeNode* node, long long currentPathSum) {
        if (!node) return;
        // 1. Update current path sum
        currentPathSum += node->val;
        // 2. Check if a valid path ends at this node
        if(prefixSumMap.count(currentPathSum - target))
            count += prefixSumMap[currentPathSum - target];
        // 3. Add current path sum to map for descendants
        prefixSumMap[currentPathSum]++;
        // 4. Recurse for children
        dfs(node->left, currentPathSum);
        dfs(node->right, currentPathSum);
        // 5. Backtrack: remove current path sum from map
        prefixSumMap[currentPathSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        prefixSumMap[0] = 1; // Base case for paths starting at the root
        dfs(root, 0);
        return count;
    }
};

int main() {
    cout << "## 3. Path Sum III ##" << endl;
    Solution_PathSum sol;
    // Example tree: [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    
    int target = 8;
    cout << "Target Sum: " << target << endl;
    cout << "Number of paths: " << sol.pathSum(root, target) << endl << endl;
}