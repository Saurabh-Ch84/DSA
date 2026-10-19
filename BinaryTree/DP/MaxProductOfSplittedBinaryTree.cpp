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

class Solution2{
    int MOD=1e9+7;
    int DFS1(TreeNode* root){
        if(!root) return 0;
        int left=DFS1(root->left);
        int right=DFS1(root->right);
        return root->val+left+right;
    }
    int DFS2(TreeNode* root,long long &res,int totalSum){
        if(!root) return 0;
        int left=DFS2(root->left,res,totalSum);
        int right=DFS2(root->right,res,totalSum);
        int sum=root->val+left+right;
        long long temp=1LL*(totalSum-sum)*sum;
        res=max(res,temp);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        int totalSum=DFS1(root);
        long long res=0;
        DFS2(root,res,totalSum);
        return res%MOD;
    }
};

class Solution1 {
    int MOD=1e9+7;
    unordered_map<TreeNode*,int> hashMap;
    int DFS1(TreeNode* root){
        if(!root) return 0;
        int left=DFS1(root->left);
        int right=DFS1(root->right);
        return hashMap[root]=root->val+left+right;
    }
    void DFS2(TreeNode* root,long long &res,int totalSum){
        if(!root) return ;
        DFS2(root->left,res,totalSum);
        DFS2(root->right,res,totalSum);
        long long temp=1LL*(totalSum-hashMap[root])*hashMap[root];
        res=max(res,temp);
    }
public:
    int maxProduct(TreeNode* root) {
        int totalSum=DFS1(root);
        long long res=0;
        DFS2(root,res,totalSum);
        return res%MOD;
    }
};

int main(){

return 0;
}