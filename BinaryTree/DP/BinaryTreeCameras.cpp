#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    // 0-> need help, 1->I got you, 2->look after yourself.
    int DFS(TreeNode* root,int &cameras){
        if(!root) return 2;
        int left=DFS(root->left,cameras);
        int right=DFS(root->right,cameras);
        if(left==0 || right==0){
            cameras++;
            return 1;
        }
        if(left==2 && right==2){
            return 0;
        }
        else return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
        int cameras=0;
        if(DFS(root,cameras)==0) cameras++;
        return cameras;
    }
};

int main(){

return 0;
}