#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
    Node *makeTree(unordered_map<int,int> &hashMap,vector<int> &inorder,vector<int> &preorder,
                    int n,int low,int high,int &left)
    {
        if(left>=n || low>high || high>=n) return nullptr;
        int val=preorder[left++];
        int right=hashMap[val];
        Node *node=new Node(val);
        node->left=makeTree(hashMap,inorder,preorder,n,low,right-1,left);
        node->right=makeTree(hashMap,inorder,preorder,n,right+1,high,left);
        return node;
    }
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        unordered_map<int,int> hashMap;
        int n=preorder.size();
        for(int i=0;i<n;i++)
            hashMap[inorder[i]]=i;
        int idx=0;
        return makeTree(hashMap,inorder,preorder,n,0,n-1,idx);
    }
};

class Solution2 {
    TreeNode *makeTree(unordered_map<int,int> &hashMap, vector<int> &inorder, vector<int> &postorder,
                      int &idx, int n, int low, int high)
    {
        if(idx < 0 || low > high || high >= n) return nullptr;

        int val = postorder[idx--];
        int indx = hashMap[val];
        TreeNode *node = new TreeNode(val);

        // Build right subtree first due to postorder nature
        node->right = makeTree(hashMap, inorder, postorder, idx, n, indx + 1, high);
        node->left = makeTree(hashMap, inorder, postorder, idx, n, low, indx - 1);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hashMap;
        int n = inorder.size();

        for(int i = 0; i < n; i++)
            hashMap[inorder[i]] = i;

        int idx = n - 1;
        return makeTree(hashMap, inorder, postorder, idx, n, 0, n - 1);
    }
};


int main(){

return 0;
}