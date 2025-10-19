#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};


class Solution {
    
    int countNodes(Node* root) {
    Node* curr = root;
    int count = 0;
    while (curr) {
        if (!curr->left) {
            count++;
            curr = curr->right;
        } else {
            Node* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if (!prev->right) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}
    
    int morrisTraversal(Node* root,int k){
        Node* curr=root;
        int count=0;
        while(curr){
            if(!curr->left){
                if(++count==k) return curr->data;
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    if(++count==k) return curr->data;
                    curr=curr->right;
                }
            }
        }
        return -1;
    }
    
  public:
    int findMedian(Node* root) {
        // Code here
        int n=countNodes(root);
        int k=(n+1)/2;
        return morrisTraversal(root,k);
    }
};

int main(){

return 0;
}