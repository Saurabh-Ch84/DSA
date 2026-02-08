#include<iostream>
#include<vector>
#include<algorithm>
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

using pbi=pair<bool,int>;
class Solution1 {
    pbi recursion(TreeNode* root){
        if(!root) return {true,0};
        pbi left=recursion(root->left);
        pbi right=recursion(root->right);
        int h=1+max(left.second,right.second);
        if(!left.first || !right.first || abs(left.second-right.second)>1) 
            return {false,h};
        return {true,h};
    }
public:
    bool isBalanced(TreeNode* root) {
        return recursion(root).first;
    }
};

class Solution2 {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int prefix=1, suffix=1, n=arr.size(), maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(!prefix) prefix=1;
            if(!suffix) suffix=1;
            prefix=prefix*arr[i];
            suffix=suffix*arr[n-i-1];
            maxi=max({maxi,prefix,suffix});
        }
        return maxi;
    }
};

int main(){

return 0;
}