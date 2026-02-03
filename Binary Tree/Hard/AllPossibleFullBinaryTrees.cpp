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

using memo_t=unordered_map<int,vector<TreeNode*>> ;

class Solution {
    vector<TreeNode*> recursion(int n,memo_t &memo){
        if(n%2==0) return {};
        if(n==1) return {new TreeNode(0)};
        if(memo.count(n)) return memo[n];
        vector<TreeNode*> result;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftFBTs=recursion(i,memo);
            vector<TreeNode*> rightFBTs=recursion(n-i-1,memo);
            for(TreeNode* leftNode: leftFBTs){
                for(TreeNode* rightNode: rightFBTs){
                    TreeNode* node=new TreeNode(0);
                    node->left=leftNode;
                    node->right=rightNode;
                    result.push_back(node);
                }
            }
        }
        return memo[n]=result;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        memo_t memo;
        return recursion(n,memo);
    }
};

int main(){

return 0;
}