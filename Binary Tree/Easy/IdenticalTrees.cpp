#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left,*right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        if(r1->data!=r2->data) return false;
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
    }
};

int main(){

return 0;
}