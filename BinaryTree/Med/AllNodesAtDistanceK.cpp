#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// striver's approach

class Solution1{
    void buildNodeParentMap(unordered_map<TreeNode*,TreeNode*> &parentMap,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parentMap[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    parentMap[node->right]=node;
                }
            }
        }
    }

    void DFS(TreeNode *target,unordered_map<TreeNode*,TreeNode*> &parentMap,
             int k,vector<int> &ans,unordered_set<TreeNode*> &visited){
        if(!target) return ;
        visited.insert(target);
        if(k<=0){
            if(k==0) ans.push_back(target->val);
            return ;
        }
        if(!visited.count(parentMap[target])) DFS(parentMap[target],parentMap,k-1,ans,visited);
        if(target->left && !visited.count(target->left)) DFS(target->left,parentMap,k-1,ans,visited);
        if(target->right && !visited.count(target->right)) DFS(target->right,parentMap,k-1,ans,visited);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parentMap;
        buildNodeParentMap(parentMap,root);
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        DFS(target,parentMap,k,ans,visited);
        return ans;
    }
};

// my approach
class Solution2 {
    void buildGraph(unordered_map<TreeNode*,vector<TreeNode*>> &adjMap,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    adjMap[node].push_back(node->left);
                    adjMap[node->left].push_back(node);
                }
                if(node->right){
                    q.push(node->right);
                    adjMap[node].push_back(node->right);
                    adjMap[node->right].push_back(node);
                }
            }
        }
    }

    void DFS(TreeNode *target,unordered_map<TreeNode*,vector<TreeNode*>> &adjM,
             int k,vector<int> &ans,unordered_set<TreeNode*> &visited){
        
        visited.insert(target);
        if(k<=0){
            if(k==0) ans.push_back(target->val);
            return ;
        }
        for(TreeNode *node:adjM[target])
            if(!visited.count(node)) DFS(node,adjM,k-1,ans,visited);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,vector<TreeNode*>> adjMap;
        buildGraph(adjMap,root);
        vector<int> ans;
        unordered_set<TreeNode*> visited;
        DFS(target,adjMap,k,ans,visited);
        return ans;
    }
};

int main(){

return 0;
}