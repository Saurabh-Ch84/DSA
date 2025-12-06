#include<iostream>
#include<vector>
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

class Solution {
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q || p->val!=q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool left=isSubtree(root->left,subRoot);
        if(left) return true;
        bool right=isSubtree(root->right,subRoot);
        if(right) return true;
        return isSameTree(root,subRoot);
    }
};


class Solution {
    void serialize(TreeNode* root,string &rootStr){
        if(!root){
            rootStr=rootStr+"#!";
            return ;
        }
        rootStr=rootStr+"#"+to_string(root->val)+',';
        serialize(root->left,rootStr);
        serialize(root->right,rootStr);
    }

    bool KMP(string &rootStr,string &subRootStr){
        int m=subRootStr.length();
        vector<int> lps(m,0);
        int len=0,i_=1;
        while(i_<m){
            if(subRootStr[i_]==subRootStr[len]){
                len++;
                lps[i_]=len;
                i_++;
            }
            else{
                if(len) len=lps[len-1];
                else i_++;
            }
        }
        int n=rootStr.length();
        int j=0,i=0;
        while(i<n){
            if(rootStr[i]==subRootStr[j]){
                i++;
                j++;
                if(j==m) return true;
            }
            else{
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootStr,subRootStr;
        serialize(root,rootStr);
        serialize(subRoot,subRootStr);
        return KMP(rootStr,subRootStr);
    }
};

int main(){

return 0;
}