#include<iostream>
using namespace std;

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


class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(!root) return 0;
        int data=0;
        if(root->data>=l && root->data<=r)
            data=root->data;
        return data+nodeSum(root->left,l,r)+nodeSum(root->right,l,r);
    }
};

int main(){

return 0;
}
