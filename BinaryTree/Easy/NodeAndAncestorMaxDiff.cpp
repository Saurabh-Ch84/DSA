#include<bits/stdc++.h>
using namespace std;

// Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
    void DFS(Node* root,int MaxAncestorValue,int &diff,bool isRoot){
        if(!root) return ;
        int currVal=root->data;
        if(!isRoot) diff=max(diff,MaxAncestorValue-currVal);
        DFS(root->left,max(MaxAncestorValue,currVal),diff,0);
        DFS(root->right,max(MaxAncestorValue,currVal),diff,0);
    }
  public:
    int maxDiff(Node* root) {
        // code here
        int diff=-1e9;
        DFS(root,-1,diff,1);
        return diff;
    }
};

int main(){

return 0;
}