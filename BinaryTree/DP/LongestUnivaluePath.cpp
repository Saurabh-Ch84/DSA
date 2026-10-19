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
    int inf=1e9;
    pair<int,int> DFS(TreeNode* root,int &res){
        if(!root) return {0,inf};
        pair<int,int> left=DFS(root->left,res);
        pair<int,int> right=DFS(root->right,res);
        pair<int,int> temp={0,root->val};
        pair<int,int> ans={0,root->val};
        if(temp.second==left.second){
            temp.first=1+left.first;
            ans.first=1+left.first;
        }
        if(temp.second==right.second){
            temp.first=temp.first+1+right.first;
            ans.first=max(ans.first,1+right.first);
        }
        res=max(res,temp.first);
        return ans;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        DFS(root,res);
        return res;
    }
};

int main(){

return 0;
}