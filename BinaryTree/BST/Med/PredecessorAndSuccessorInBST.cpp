#include<iostream>
#include<vector>
using namespace std;

//BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    void getSuccessor(Node* root,Node* &s,int key){
        if(!root) return ;
        int val=root->data;
        if(val>key){
            s=root;
            getSuccessor(root->left,s,key);
        }
        else getSuccessor(root->right,s,key);
    }
    
    void getPredecessor(Node* root,Node* &p,int key){
        if(!root) return ;
        int val=root->data;
        if(val<key){
            p=root;
            getPredecessor(root->right,p,key);
        }
        else getPredecessor(root->left,p,key);
    }
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pred=nullptr,* succ=nullptr;
        getSuccessor(root,succ,key);
        getPredecessor(root,pred,key);
        return {pred,succ};
    }
};

int main(){

return 0;
}