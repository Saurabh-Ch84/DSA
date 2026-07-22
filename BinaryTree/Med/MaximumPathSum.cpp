#include<iostream>
#include<climits>
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
    int DFS(Node *root,int &maxSum){
        if(!root) return 0;
        //sum is negative then do not take.
        int leftSum=max(DFS(root->left,maxSum),0);
        int rightSum=max(DFS(root->right,maxSum),0);
        maxSum=max(maxSum,root->data+leftSum+rightSum);
        return root->data+max(leftSum,rightSum);
    }
  public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int maxSum=INT_MIN;
        DFS(root,maxSum);
        return maxSum;
    }
};

int main(){

return 0;
}