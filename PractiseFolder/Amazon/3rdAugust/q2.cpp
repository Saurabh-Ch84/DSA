#include<iostream>
#include<vector>
using namespace std;

//Given a sorted array make a height balanced BST out of it

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
    TreeNode* makeBalancedBST(vector<int> &nums,int low,int high,int n){
        if(low>high) return nullptr;
        int mid=low+(high-low)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=makeBalancedBST(nums,low,mid-1,n);
        node->right=makeBalancedBST(nums,mid+1,high,n);
        return node;
    }
        public:
    TreeNode* BST(vector<int> &nums){
        int n=nums.size();
        return makeBalancedBST(nums,0,n-1,n);
    }

    void printPreorder(TreeNode *root){
        if(!root) return;
        cout<<root->val<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
    }

    void printInorder(TreeNode *root){
        if(!root) return;
        printInorder(root->left);
        cout<<root->val<<" ";
        printInorder(root->right);
    }
};

int main(){
    Solution s;
    vector<int> nums1={1,2,3};
    vector<int> nums2={-10,-3,0,5,9};
    vector<int> nums3={11,22,33,45,67};
    cout<<"InOrder: ";
    s.printInorder(s.BST(nums2));
    cout<<"preOrder: ";
    s.printPreorder(s.BST(nums2));
    // s.printInorder(s.BST(nums2));
return 0;
}