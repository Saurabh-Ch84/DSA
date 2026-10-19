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
    pair<int,int> DFS(TreeNode* root,int &res){
        if(!root) return {0,0};
        pair<int,int> left=DFS(root->left,res);
        pair<int,int> right=DFS(root->right,res);
        pair<int,int> ans={0,0};
        ans.first=root->val+left.second+right.second;
        ans.second=max(left.first,left.second)+max(right.first,right.second);
        res=max({res,ans.first,ans.second});
        return ans;
    }
public:
    int rob(TreeNode* root) {
        int res=0;
        DFS(root,res);
        return res;
    }
};

int main(){

return 0;
}