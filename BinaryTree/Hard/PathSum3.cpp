#include<iostream>
#include<vector>
#include<unordered_map>
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

using memo_t=unordered_map<long long,int> ;
class Solution {
    void recursion(TreeNode* root,int targetSum,int &count,memo_t &memo,long long currSum){
        if(!root) return ;
        currSum+=root->val;
        if(memo.count(currSum-targetSum))
            count+=memo[currSum-targetSum];
        memo[currSum]++;
        recursion(root->left,targetSum,count,memo,currSum);
        recursion(root->right,targetSum,count,memo,currSum);
        memo[currSum]--;    
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        memo_t memo;
        memo[0]=1;
        recursion(root,targetSum,count,memo,0);
        return count;
    }
};

int main(){

return 0;
}