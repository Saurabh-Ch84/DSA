#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    pair<int,int> DFS(TreeNode* root,int &count){
        if(!root) return {0,0};
        auto leftSubtree=DFS(root->left,count);
        auto rightSubtree=DFS(root->right,count);
        int sumOfSubtreeNodes=leftSubtree.first+rightSubtree.first+root->val;
        int countOfSubtreeNodes=leftSubtree.second+rightSubtree.second+1;
        int subtreeAvg=sumOfSubtreeNodes/countOfSubtreeNodes;
        if(subtreeAvg==root->val) count++;
        return {sumOfSubtreeNodes,countOfSubtreeNodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        DFS(root,count);
        return count;
    }
};

int main(){

return 0;
}