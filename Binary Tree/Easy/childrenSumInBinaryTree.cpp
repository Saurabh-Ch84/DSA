#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    bool isLeaf(Node *root){
        if(root && !root->left && !root->right) return true;
        return false;
    }

  public:
    int isSumProperty(Node *root) {
        if(!root) return true;
        if(isLeaf(root)) return true;

        bool left = isSumProperty(root->left);
        if(!left) return false;

        int leftVal = (root->left) ? root->left->data : 0;

        bool right = isSumProperty(root->right);
        if(!right) return false;

        int rightVal = (root->right) ? root->right->data : 0;

        return root->data == leftVal + rightVal;
    }
};

int main(){

return 0;
}