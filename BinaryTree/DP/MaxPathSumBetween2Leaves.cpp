#include<bits/stdc++.h>
using namespace std;

// Node Structure
class Node {
        public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    int inf=-1e9;
    int DFS(Node* root,int &res){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        int left=DFS(root->left,res), right=DFS(root->right,res);
        if(root->left && root->right){
            int temp=left+right+root->data;
            res=max(res,temp);
            int ans=max(left,right)+root->data;
            return ans;
        }
        int ans=0;
        if(!root->right) ans=left+root->data;
        else ans=right+root->data;
        return ans;
    }
  public:
    int maxPathSum(Node *root) {
        // code here
        int res=inf;
        DFS(root,res);
        return (res==inf? -1: res);
    }
};

int main(){

return 0;
}