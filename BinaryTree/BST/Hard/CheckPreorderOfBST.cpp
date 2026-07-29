#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    unordered_map<int,int> hashMap;
    using vint=vector<int>;
    class Node{
            public:
        int val;
        Node *left, *right;
        Node(int val=0): val(val), left(nullptr), right(nullptr){}
    };
    using pNb=pair<Node*,bool>;
    pNb makeTree(int &idx,int low,int high,int n,int ub,int lb,vint &preorder,vint &inorder){
        if(idx>=n || low>high) return {nullptr,true};
        int val=preorder[idx++];
        if(val>=ub || val<=lb) return {nullptr,false};
        int inorderIdx=hashMap[val];
        Node* node=new Node(val);
        pNb leftSubTree=makeTree(idx,low,inorderIdx-1,n,val,lb,preorder,inorder);
        pNb rightSubTree=makeTree(idx,inorderIdx+1,high,n,ub,val,preorder,inorder);
        if(!leftSubTree.second || !rightSubTree.second) return {nullptr,false};
        node->left=leftSubTree.first;
        node->right=rightSubTree.first;
        return {node,true};
    }
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int n=arr.size();
        vint inorder=arr;
        sort(inorder.begin(),inorder.end());
        hashMap.empty();
        
        for(int i=0;i<n;i++)
            hashMap[inorder[i]]=i;
        int idx=0;
        pNb root=makeTree(idx,0,n-1,n,INT_MAX,INT_MIN,arr,inorder);
        return (root.second); // can return root.first too.
    }
};

class Solution2 {
    using vint=vector<int>;
    class Node{
            public:
        int val;
        Node *left, *right;
        Node(int val=0): val(val), left(nullptr), right(nullptr){}
    };
    using pNb=pair<Node*,bool>;
    pNb makeTree(int &idx,int n,int ub,int lb,vint &preorder){
        if(idx>=n || preorder[idx]>=ub) return {nullptr,true};
        int val=preorder[idx++];
        if(val>=ub || val<=lb) return {nullptr,false};
        Node* node=new Node(val);
        pNb leftSubTree=makeTree(idx,n,val,lb,preorder);
        pNb rightSubTree=makeTree(idx,n,ub,val,preorder);
        if(!leftSubTree.second || !rightSubTree.second) return {nullptr,false};
        node->left=leftSubTree.first;
        node->right=rightSubTree.first;
        return {node,true};
    }
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int n=arr.size(), idx=0;
        pNb root=makeTree(idx,n,INT_MAX,INT_MIN,arr);
        return (root.second);
    }
};

class Solution3 {
    using vint=vector<int>;
    bool isBST(int &idx,int n,int lb,int ub,vint &arr){
        if(idx>=n || arr[idx]>=ub) return true;
        int val=arr[idx];
        if(val<=lb || val>=ub) return false;
        idx++;
        return (isBST(idx,n,lb,val,arr) && isBST(idx,n,val,ub,arr));
    }
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int idx=0, n=arr.size();
        return isBST(idx,n,INT_MIN,INT_MAX,arr);
    }
};

int main(){

return 0;
}