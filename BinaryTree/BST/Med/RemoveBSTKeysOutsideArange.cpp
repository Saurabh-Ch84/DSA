#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        if(!root) return root;
        Node* lefty=removekeys(root->left,l,r);
        Node* righty=removekeys(root->right,l,r);
        int data=root->data;
        if(data>r) return lefty;
        if(data<l) return righty;
        root->left=lefty;
        root->right=righty;
        return root;
    }
};

int main(){

return 0;
}