#include<iostream>
#include<climits>
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

//striver's solution    
class Solution2 {
    void DFS(TreeNode* root,int &sum,int &maxDepth,int level=0){
        if(!root) return ;
        if(level==maxDepth)
            sum+=root->val;
        else if(level>maxDepth){
            sum=root->val;
            maxDepth=level;
        }
        DFS(root->left,sum,maxDepth,level+1);
        DFS(root->right,sum,maxDepth,level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0,maxDepth=INT_MIN;
        DFS(root,sum,maxDepth);
        return sum;
    }
};

//My solution
class Solution1 {
    int heightOfTree(TreeNode* root){
        if(!root) return 0;
        return 1+max(heightOfTree(root->left),heightOfTree(root->right));
    }
    int sumOfDeepNodes(TreeNode* root,int depth){
        if(!root) return 0;
        if(depth==1) return root->val;
        return sumOfDeepNodes(root->left,depth-1)
                    +
               sumOfDeepNodes(root->right,depth-1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int height=heightOfTree(root);
        return sumOfDeepNodes(root,height);
    }
};

int main(){

return 0;
}