#include<iostream>
#include<climits>
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
    void DFS(TreeNode* root,int &count,int maxi){
        if(!root) return ;
        int val=root->val;
        if(val>=maxi) count++;
        DFS(root->left,count,max(maxi,val));
        DFS(root->right,count,max(maxi,val));
    }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        DFS(root,count,INT_MIN);
        return count;
    }
};

int main(){

return 0;
}