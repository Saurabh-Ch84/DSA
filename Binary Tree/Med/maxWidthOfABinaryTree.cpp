#include<iostream>
#include<queue>
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

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long>> q;
        long maxWidth=0;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long leftBound=q.front().second;
            long rightBound=q.back().second;
            maxWidth=max(maxWidth,rightBound-leftBound+1);
            for(int i=0;i<size;i++){
                TreeNode *node=q.front().first;
                long bound=q.front().second-leftBound;// necessary
                q.pop();
                if(node->left) q.push({node->left,2*bound+1});
                if(node->right) q.push({node->right,2*bound+2});
            }
        }
        return (int)maxWidth;
    }
};

int main(){

return 0;
}