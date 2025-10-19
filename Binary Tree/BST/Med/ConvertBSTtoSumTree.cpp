#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    void inorderRec(Node* root,vector<int> &inorder){
        if(!root) return ;
        inorderRec(root->left,inorder);
        inorder.push_back(root->data);
        inorderRec(root->right,inorder);
    }
    
    vector<int> precompute(vector<int> &inorder,int n){
        vector<int> suffix(n,0);
        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1]+inorder[i+1];
        return suffix;
    }
    
    void update(Node* root,vector<int> &suffix,int &ptr,int n){
        if(!root || ptr>=n) return ;
        update(root->left,suffix,ptr,n);
        root->data=suffix[ptr++];
        update(root->right,suffix,ptr,n);
    }
    
  public:
    void transformTree(Node *root) {
        // code here
        vector<int> inorder;
        inorderRec(root,inorder);
        int n=inorder.size();
        vector<int> suffix=precompute(inorder,n);
        int ptr=0;
        update(root,suffix,ptr,n);
    }
};

int main(){

return 0;
}