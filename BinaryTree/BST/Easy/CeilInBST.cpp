#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//striver's approach
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

//my approach
bool getCeil(Node *root,int input,int &ans){
    if(!root) return false;
    int val=root->data;
    if(val>input){
        ans=min(ans,val);
        return getCeil(root->left,input,ans);
    }
    if(val<input)
        return getCeil(root->right,input,ans);
    ans=val;
    return true;
}

int findCeil(Node* root, int input) {
    // Your code here
    int ans=INT_MAX;
    if(getCeil(root,input,ans) || ans!=INT_MAX) return ans;
    return -1;
}

int main(){

return 0;
}