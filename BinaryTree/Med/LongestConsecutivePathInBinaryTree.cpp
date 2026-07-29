#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    int DFS(Node* root, int &ans) {
        if (!root) return 0;
        int leftLen = DFS(root->left, ans);
        int rightLen = DFS(root->right, ans);
        int currentLen = 1; // At least the node itself
        
        if (root->left && root->left->data == root->data + 1)
            currentLen = max(currentLen, 1 + leftLen);
        
        if (root->right && root->right->data == root->data + 1)
            currentLen = max(currentLen, 1 + rightLen);
        
        ans = max(ans, currentLen);
        return currentLen;
    }

public:
    int longestConsecutive(Node* root) {
        if (!root) return 0;
        int ans = 0;
        DFS(root, ans);
        return (ans<=1? -1: ans);
    }
};

int main(){

return 0;
}