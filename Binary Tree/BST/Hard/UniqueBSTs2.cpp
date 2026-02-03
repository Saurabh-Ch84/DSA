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

using memo_t=unordered_map<int,unordered_map<int,vector<TreeNode*>>>;

class Solution {
    vector<TreeNode*> recursion(int start,int end,memo_t &memo){
        if(start>end) return {nullptr};
        else if(start==end) return {new TreeNode(start)};
        if(memo.count(start) && memo[start].count(end)){
            return memo[start][end];
        }
        vector<TreeNode*> result;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftBSTs=recursion(start,i-1,memo);
            vector<TreeNode*> rightBSTs=recursion(i+1,end,memo);
            for(TreeNode* leftNode: leftBSTs){
                for(TreeNode* rightNode: rightBSTs){
                    TreeNode* node=new TreeNode(i);
                    node->left=leftNode;
                    node->right=rightNode;
                    result.push_back(node);
                }
            }
        }
        return memo[start][end]=result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        memo_t memo;
        return recursion(1,n,memo);
    }
};

int main(){

return 0;
}