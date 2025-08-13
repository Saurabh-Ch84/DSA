#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        if(!root) return 0;
        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        return max(leftHeight,rightHeight)+1;
    }
};

int main(){

return 0;
}