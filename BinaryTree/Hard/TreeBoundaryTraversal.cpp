#include<iostream>
#include<vector>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node *root){
    if(root && !root->left && !root->right) return true;
    return false;
}

void leftBoundary(Node *root,vector<int> &res){
    Node *mover=root->left;
    while(mover){
        if(!isLeaf(mover))
            res.push_back(mover->data);
        if(mover->left) mover=mover->left;
        else mover=mover->right;
    }
}

void leafNodes(Node *root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return ;
    }
    if(root->left) leafNodes(root->left,res);
    if(root->right) leafNodes(root->right,res);
}

void rightBoundaryReverse(Node *root,vector<int> &res){
    vector<int> temp;
    Node *mover=root->right;
    while(mover){
        if(!isLeaf(mover))
            temp.push_back(mover->data);
        if(mover->right) mover=mover->right;
        else mover=mover->left;
    }
    int size=temp.size();
    while(size){
        res.push_back(temp[size-1]);
        size--;
    }
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root) return {};
        vector<int> res;
        if(!isLeaf(root)) res.push_back(root->data);
        
        leftBoundary(root,res);
        leafNodes(root,res);
        rightBoundaryReverse(root,res);
        
        return res;
    }
};

int main(){

return 0;
}