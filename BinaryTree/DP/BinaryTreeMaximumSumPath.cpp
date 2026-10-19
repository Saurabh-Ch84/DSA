#include<bits/stdc++.h>
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
    int DFS(TreeNode* root,int &res){
        if(!root) return 0;
        int left=DFS(root->left,res), right=DFS(root->right,res);
        int temp=max({0,left,right,left+right})+root->val;
        int ans=max({0,left,right})+root->val;
        res=max(res,temp);
        return ans;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=-1e9;
        DFS(root,res);
        return res;
    }
};

int main(){

return 0;
}