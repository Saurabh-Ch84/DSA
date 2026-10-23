#include<bits/stdc++.h>
using namespace std;

// BST Node Structure 
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
    int merge(vector<int> &arr,int low,int mid,int high){
        int left=low, right=mid+1, inversionCount=0;
        vector<int> temp;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                inversionCount+=(mid-left+1);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]); 
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return inversionCount;
    }
    int mergeSort(vector<int> &arr,int low,int high){
        if(low>=high) return 0;
        int mid=low+(high-low)/2;
        return mergeSort(arr,low,mid)+mergeSort(arr,mid+1,high)+merge(arr,low,mid,high);
    }
    void inorderTraversal(Node* root,vector<int> &inorder){
        if(!root) return ;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right,inorder);
    }
  public:
    int pairsViolatingBST(Node *root) {
        // code here
        vector<int> inorder;
        inorderTraversal(root,inorder);
        return mergeSort(inorder,0,inorder.size()-1);
    }
};

int main(){

return 0;
}