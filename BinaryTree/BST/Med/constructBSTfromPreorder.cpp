#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution2 {
    TreeNode* makeTree(vector<int>& preorder,int &idx,int n,int upperBound=INT_MAX){
        if(idx>=n || preorder[idx]>=upperBound) return nullptr;
        int val=preorder[idx++];
        TreeNode* node=new TreeNode(val);
        node->left=makeTree(preorder,idx,n,val);
        node->right=makeTree(preorder,idx,n,upperBound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size(),idx=0;
        return makeTree(preorder,idx,n);
    }
};

//my approach
class Solution1 {
    TreeNode* makeTree(unordered_map<int,int> &hashMap,vector<int>& preorder,
                       vector<int> &inorder,int &idx,int low,int high,int n)
    {
        if(low>high || high>=n || idx>=n) return nullptr;
        int val=preorder[idx++];
        int indx=hashMap[val];
        TreeNode* node=new TreeNode(val);
        node->left=makeTree(hashMap,preorder,inorder,idx,low,indx-1,n);
        node->right=makeTree(hashMap,preorder,inorder,idx,indx+1,high,n);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++)
            hashMap[inorder[i]]=i;
        int idx=0;
        return makeTree(hashMap,preorder,inorder,idx,0,n-1,n);
    }
};

int main(){

return 0;
}