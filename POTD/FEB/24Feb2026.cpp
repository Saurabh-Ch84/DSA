#include<iostream>
#include<vector>
#include<unordered_map>
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
	int recursion(TreeNode* root,int num){
		if(!root) return 0;
		num=(num<<1) | (root->val);
        if(!root->left && !root->right) return num;
		return recursion(root->left,num) + recursion(root->right,num);
	}
public:
    int sumRootToLeaf(TreeNode* root) {
        return recursion(root,0);
    }
};

class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        // diff vs index
        unordered_map<int,int> hashMap;
        int n=a1.size(), A=0, B=0, maxi=0;
        hashMap[0]=-1;
        for(int i=0;i<n;i++){
            A+=a1[i], B+=a2[i];
            int diff=A-B;
            if(hashMap.count(diff))
                maxi=max(maxi,i-hashMap[diff]);
            else hashMap[diff]=i;
        }
        return maxi;
    }
};

int main(){

return 0;
}