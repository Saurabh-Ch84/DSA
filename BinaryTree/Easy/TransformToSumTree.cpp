#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//A binary tree node
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
    bool isLeaf(Node* node){
        return node && !node->left && !node->right;
    }
    
    int changeTree(Node* &node){
        if(!node) return 0;
        if(isLeaf(node)){
            node->data=0;
            return 0;
        }
        int leftData=(node->left)?node->left->data:0;
        int rightData=(node->right)?node->right->data:0;
        node->data=leftData+rightData+changeTree(node->left)+changeTree(node->right);
        return node->data;
    }
  public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        // Your code here
        changeTree(node);
    }
};

int main(){

return 0;
}