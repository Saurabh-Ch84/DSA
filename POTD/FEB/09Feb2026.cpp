#include<iostream>
#include<vector>
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

using vi=vector<int>; 
class Solution1 {
    void inorderTraversal(TreeNode* root,vi &inorder){
        if(!root) return ;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }
    TreeNode* makeBalancedBST(vi &inorder,int low,int high){
        if(low>high) return nullptr;
        int mid=low+(high-low)/2;
        int val=inorder[mid];
        TreeNode* node=new TreeNode(val);
        node->left=makeBalancedBST(inorder,low,mid-1);
        node->right=makeBalancedBST(inorder,mid+1,high);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vi inorder;
        inorderTraversal(root,inorder);
        int low=0, high=inorder.size()-1;
        return makeBalancedBST(inorder,low,high);
    }
};

class Solution2 {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0,high=arr.size()-1;
        int minIndx=0,minNum=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]<=arr[high]){
                if(minNum>arr[low]){
                    minNum=arr[low];
                    minIndx=low;
                }
                break;
            }
            else if(arr[low]<=arr[mid]){
                if(minNum>arr[low]){
                    minNum=arr[low];
                    minIndx=low;
                }
                low=mid+1;
            }
            else{
                if(minNum>arr[mid]){
                    minNum=arr[mid];
                    minIndx=mid;
                }
                high=mid-1;
            }
        }
        return minIndx;
    }
};

int main(){

return 0;
}