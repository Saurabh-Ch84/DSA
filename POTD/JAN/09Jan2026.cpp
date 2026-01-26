#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using  uno_mapTi=unordered_map<TreeNode*,int>;

class Solution {
    void createMap(TreeNode* root,uno_mapTi &hashMap,int d,int &maxDep){
        if(!root) return ;
        hashMap[root]=d;
        maxDep=max(maxDep,d);
        createMap(root->left,hashMap,d+1,maxDep);
        createMap(root->right,hashMap,d+1,maxDep);
    }
    TreeNode* modLCA(TreeNode* root,uno_mapTi &hashMap,int maxDep){
        if(!root || hashMap[root]==maxDep) return root;
        TreeNode* left=modLCA(root->left,hashMap,maxDep);
        TreeNode* right=modLCA(root->right,hashMap,maxDep);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        uno_mapTi hashMap;
        int maxDep=0;
        createMap(root,hashMap,0,maxDep);
        return modLCA(root,hashMap,maxDep);
    }
};

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size(), left=0, right=0, count=0;
        unordered_map<int,int> hashMap;
        while(right<n){
            int num=arr[right];
            hashMap[num]++;
            while(hashMap.size()>k){
                int prev=arr[left++];
                hashMap[prev]--;
                if(!hashMap[prev]){
                    hashMap.erase(prev);
                }
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
};

int main(){

return 0;
}