#include<iostream>
#include<climits>
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

//striver's approach
class Solution1 {
    class BSTreeInfo{
            public:
        int size,minNode,maxNode;
        BSTreeInfo(int size=0,int minNode=INT_MAX,int maxNode=INT_MIN){
            this->size=size; 
            this->minNode=minNode; 
            this->maxNode=maxNode; 
        }
    };
    
    bool isBSTreeValid(const BSTreeInfo &leftSubTree,const BSTreeInfo &rightSubTree,Node *node){
        int val=node->data;
        return (val>leftSubTree.maxNode && val<rightSubTree.minNode);
    }
    
    BSTreeInfo findLargestBST(Node* root){
        if(!root) return BSTreeInfo();
        BSTreeInfo leftSubTree=findLargestBST(root->left);
        BSTreeInfo rightSubTree=findLargestBST(root->right);
        int sizeOfBST=0;
        if(isBSTreeValid(leftSubTree,rightSubTree,root)){
            sizeOfBST=leftSubTree.size+rightSubTree.size+1;
            int minNode=min(root->data,leftSubTree.minNode);
            int maxNode=max(root->data,rightSubTree.maxNode);
            return BSTreeInfo(sizeOfBST,minNode,maxNode);
        }
        sizeOfBST=max(leftSubTree.size,rightSubTree.size);
        return BSTreeInfo(sizeOfBST,INT_MIN,INT_MAX);
    }
  public:
    int largestBst(Node *root) {
        return findLargestBST(root).size;
    }
};

//my approach
class Solution1 {
    bool isBST(Node* root,int &count,int lb=INT_MIN,int ub=INT_MAX){
        if(!root) return true;
        count++;
        int val=root->data;
        if(val<=lb || val>=ub) return false;
        return isBST(root->left,count,lb,val) &&
                isBST(root->right,count,val,ub);
    }
  public:
    int largestBst(Node *root,int count=0) {
        // Your code here
        if(!root) return 0;
        if(isBST(root,count)) return count;
        return max(largestBst(root->left),largestBst(root->right));
    }
};

int main(){

return 0;
}