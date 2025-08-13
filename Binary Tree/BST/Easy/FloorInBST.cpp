#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to search a node in BST.
class Solution {
  public:
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        Node* curr=root;
        while(curr){
            int val=curr->data;
            if(val==x) return val;
            if(val<x){
                ans=val;
                curr=curr->right;
            }
            if(val>x) curr=curr->left;
        }
        return ans;
    }
};

int main(){

return 0;
}