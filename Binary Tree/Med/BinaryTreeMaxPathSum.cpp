#include<iostream>
#include<algorithm>
#include<climits>
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
    int DFS(TreeNode* root,int &maxi){
        if(!root) return 0;
        int val=root->val;
        int left=DFS(root->left,maxi);
        int right=DFS(root->right,maxi);
        maxi=max({maxi,val+left+right,val+max({0,left,right})});
        return val+max({0,left,right});
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        DFS(root,maxi);
        return maxi;
    }
};

int main(){

return 0;
}