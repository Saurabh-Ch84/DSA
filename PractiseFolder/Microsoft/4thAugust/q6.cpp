#include<iostream>
#include<vector>
using namespace std;

//Given A sorted array make a balanced BST out of it.Then find the min distance between any 2 given nodes.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    TreeNode* makeBST(vector<int> &nums,int low,int high){
        if(low>high) return nullptr;
        int mid=(low+high)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=makeBST(nums,low,mid-1);
        node->right=makeBST(nums,mid+1,high);
        return node;
    }

    TreeNode* LCA(TreeNode* root,int p,int q){
        if(!root || root->val==p || root->val==q) return root;
        int val=root->val;
        if(val>p && val>q) return LCA(root->left,p,q);
        if(val<p && val<q) return LCA(root->right,p,q);
        return root;
    }

    int dist(TreeNode* node,int x){
        if(!node) return 0;
        int val=node->val;
        if(val<x) return 1+dist(node->right,x);
        if(val>x) return 1+dist(node->left,x);
        return 0;
    }
        public:
    int fun(vector<int>& nums,int p,int q){
        TreeNode* root=makeBST(nums,0,nums.size()-1);
        TreeNode* node=LCA(root,p,q);
        // cout<<node->val<<endl;
        return dist(node,p)+dist(node,q);
    }
};

int main(){
    Solution s;
    vector<int> nums={-1,2,5,6,8,13,18,57};
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    cout<<s.fun(nums,n,m)<<endl;
return 0;
}