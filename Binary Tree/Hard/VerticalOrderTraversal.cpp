#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
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

class Solution {
    void inorder(TreeNode* node,map<pair<int,int>,vector<int>> &levelNode
                 ,int &firstLevel,int &lastLevel,pair<int,int> p={0,0}){  
            if(node==nullptr) return ;
            inorder(node->left,levelNode,firstLevel,lastLevel,{p.first+1,p.second-1});
            levelNode[p].push_back(node->val);
            firstLevel=min(p.second,firstLevel);
            lastLevel=max(p.second,lastLevel);
            inorder(node->right,levelNode,firstLevel,lastLevel,{p.first+1,p.second+1});
        }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<pair<int,int>,vector<int>> levelNode;
        int firstLevel=0,lastLevel=0;
        inorder(root,levelNode,firstLevel,lastLevel);
        int levelsTotal=lastLevel-firstLevel+1;
        vector<vector<int>> answer(levelsTotal);
        for(pair<pair<int,int>,vector<int>> p:levelNode){
            vector<int> nodes=p.second;
            if(nodes.size()>1) sort(nodes.begin(),nodes.end());
            int pseudoLevel=p.first.second;
            int level=pseudoLevel-firstLevel;
            for(int &node:nodes) answer[level].push_back(node);
        }
        return answer;
    }
};

int main(){

return 0;
}