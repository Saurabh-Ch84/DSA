#include<bits/stdc++.h>
using namespace std;

// Structure of Binary Tree Node
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
    unordered_map<int,int> hashMap;
    using vint=vector<int>;
    Node* recursion(int &idx,int n,int low,int high,vint &pre,vint &preMirror){
        if(low>high || idx>=n) return nullptr;
        int val=pre[idx++];
        Node* node=new Node(val);
        if(low==high) return node;
        int mid=hashMap[pre[idx]];
        node->left=recursion(idx,n,mid,high,pre,preMirror);
        node->right=recursion(idx,n,low+1,mid-1,pre,preMirror);
        return node;
    }
  public:
    Node *constructBinaryTree(vint &pre,vint &preMirror) {
        // code here
        hashMap.clear();
        int n=pre.size(), idx=0;
        for(int i=0;i<n;i++){
            hashMap[preMirror[i]]=i;
        }
        return recursion(idx,n,0,n-1,pre,preMirror);
    }
};

int main(){

return 0;
}