#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
private:
    bool isBSTHelper(Node* root, int leftVal, int rightVal) {
        if (!root) return true;
        int rootVal = root->data;
        if (rootVal <= leftVal || rootVal >= rightVal) return false;
        return isBSTHelper(root->left, leftVal, rootVal) 
            && isBSTHelper(root->right, rootVal, rightVal);
    }
public:
    bool isBST(Node* root) {
        return isBSTHelper(root, INT_MIN, INT_MAX);
    }
};


int main(){

return 0;
}