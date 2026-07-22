#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
        public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

class Solution {
    Node *makeTree(int preStart, int preEnd, vector<int> &pre, int postStart, int postEnd,
                  unordered_map<int,int> &postIndexMap)
    {
        if(preStart > preEnd || postStart > postEnd) return nullptr;
        
        Node *node = new Node(pre[preStart]);
        
        // Base case: single node
        if(preStart == preEnd) return node;
        
        // The next element in preorder is the left child's root
        int leftRootVal = pre[preStart + 1];
        int leftPostEnd = postIndexMap[leftRootVal];
        int leftSize = leftPostEnd - postStart + 1;
        
        // Build left subtree
        node->left = makeTree(preStart + 1, preStart + leftSize, pre, 
                              postStart, leftPostEnd, postIndexMap);
        
        // Build right subtree
        node->right = makeTree(preStart + leftSize + 1, preEnd, pre, 
                               leftPostEnd + 1, postEnd - 1, postIndexMap);
        
        return node;
    }
    
public:
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        unordered_map<int, int> postIndexMap;
        for (int i = 0; i < n; ++i)
            postIndexMap[post[i]] = i;
        
        return makeTree(0, n - 1, pre, 0, n - 1, postIndexMap);
    }
};

int main(){

return 0;
}