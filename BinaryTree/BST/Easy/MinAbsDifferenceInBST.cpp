#include<bits/stdc++.h>
using namespace std;

// Binary Tree Node Structure

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 

class Solution {
    class BST_itrerator{
        stack<Node*> st;
        void push(Node* node){
            while(node){
                st.push(node);
                node=node->left;
            }
        }
            public:    
        BST_itrerator(Node* root){
            push(root);
        }
        bool hasNext(){
            return !st.empty();
        }
        Node* next(){
            Node* node=st.top();
            st.pop();
            push(node->right);
            return node;
        }
    };
  public:
    int absDiff(Node *root) {
        // code here
        BST_itrerator itr(root);
        int prev=-1, mini=1e9;
        while(itr.hasNext()){
            int curr=itr.next()->data;
            if(prev!=-1){
                int diff=curr-prev;
                mini=min(mini,diff);
            }
            prev=curr;
        }
        return mini;
    }
};

int main(){

return 0;
}