#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n=arr.size(), m=n-k+1, left=0, right=0;
        vector<int> ans;
        unordered_map<int,int> hashMap;
        
        while(right<n){
            while(right-left+1<=k){
                int curr=arr[right++];
                hashMap[curr]++;
            }
            ans.push_back(hashMap.size());
            int prev=arr[left++];
            hashMap[prev]--;
            if(hashMap[prev]==0){
                hashMap.erase(prev);
            }
        }
        return ans;
    }
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


using ll=long long;

class Solution {
    const int MOD=1e9+7;
    ll binaryTreeSum(TreeNode *root){
        if(!root) return 0;
        return (root->val)+binaryTreeSum(root->left)+binaryTreeSum(root->right);
    }

    ll DFS(TreeNode* root,ll totalS,ll &maxP){
        if(!root) return 0;
        ll leftSub=DFS(root->left,totalS,maxP);
        ll rightSub=DFS(root->right,totalS,maxP);
        ll sum=root->val+leftSub+rightSub;
        maxP=max(maxP,(sum)*(totalS-sum));
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        ll totalS=binaryTreeSum(root), maxP=0;
        DFS(root, totalS, maxP);
        return (int)(maxP%MOD);
    }
};

int main(){

return 0;
}