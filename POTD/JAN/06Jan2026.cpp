#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int xorAns=0, left=0, right=0;
        int maxi=0;
        while(right<n){
            xorAns=xorAns^arr[right];
            if(right-left+1==k){
                maxi=max(maxi,xorAns);
                xorAns=xorAns^arr[left++];
            }
            right++;
        }
        
        return maxi;
    }
};


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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int maxSum=INT_MIN, maxLevel=0;
        int level=0;
        
        while(!q.empty()){
        	int sz=q.size();
        	int levelSum=0;
        	level++; 
        	while(sz){
        		TreeNode* node=q.front();
        		levelSum+=node->val;
        		q.pop();
        		if(node->left){
        			q.push(node->left);
        		}
        		if(node->right){
        			q.push(node->right);
        		}
        		sz--;
        	}
        	
        	if(levelSum>maxSum){
        		maxSum=levelSum;
        		maxLevel=level;
        	}
        }
        return maxLevel;
    }
};

int main(){

return 0;
}