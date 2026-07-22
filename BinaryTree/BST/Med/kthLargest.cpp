#include<iostream>
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

//Striver's approach
class Solution2 {
public:
    int kthLargest(Node* root, int k) {
        Node* curr = root;
        int count = 0;
        while (curr) {
            if (!curr->right) {
                // Visit this node
                count++;
                if (count == k) return curr->data;
                curr = curr->left;
            } else {
                Node* prev = curr->right;
                while (prev->left && prev->left != curr)
                    prev = prev->left;
                
                if (!prev->left) {
                    // Create thread
                    prev->left = curr;
                    curr = curr->right;
                } else {
                    // Thread exists, remove it and visit current
                    prev->left = nullptr;
                    count++;
                    if (count == k) return curr->data;
                    curr = curr->left;
                }
            }
        }
        return -1;
    }
};

// return the Kth largest element in the given BST rooted at 'root'
class Solution1 {
    int getKthLargest(Node *root,int &count,int k){
        if(!root) return 0;
        int rightAns=getKthLargest(root->right,count,k);
        if(rightAns) return rightAns;
        count++;
        if(k==count) return root->data;
        return getKthLargest(root->left,count,k);
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        int count=0;
        return getKthLargest(root,count,k);
    }
};

int main(){

return 0;
}