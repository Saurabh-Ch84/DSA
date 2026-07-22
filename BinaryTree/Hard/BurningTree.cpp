#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class SolutionGFG {
    void DFS(Node *root,unordered_map<Node*,Node*> &pMap,int target,Node* &targetNode){
        if(!root) return ;
        if(root->data==target) targetNode=root;
        if(root->left) pMap[root->left]=root;
        DFS(root->left,pMap,target,targetNode);
        if(root->right) pMap[root->right]=root;
        DFS(root->right,pMap,target,targetNode);
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        if(!root) return 0;
        unordered_map<Node*,Node*> parentMap;
        Node *targetNode=nullptr;
        DFS(root,parentMap,target,targetNode);
        if(!targetNode) return -1;
        
        int timeToBurn=-1;
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        
        while(!q.empty()){
            int size=q.size();
            timeToBurn++;
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parentMap.count(node) && !visited.count(parentMap[node])){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
        }
        return timeToBurn;
    }
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionLC {
    void DFS(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parentMap,
             int start,TreeNode* &targetNode){
        if(!root) return;
        if(root->val==start) targetNode=root;
        if(root->left) parentMap[root->left]=root;
        if(root->right) parentMap[root->right]=root;
        DFS(root->left,parentMap,start,targetNode);
        DFS(root->right,parentMap,start,targetNode);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        unordered_map<TreeNode*,TreeNode*> parentMap;
        TreeNode* targetNode=nullptr;
        DFS(root,parentMap,start,targetNode);
        if(!targetNode) return -1;

        int infectionTime=-1;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(targetNode);
        visited.insert(targetNode);

        while(!q.empty()){
            int size=q.size();
            infectionTime++;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parentMap.count(node) && !visited.count(parentMap[node])){
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }
        return infectionTime;
    }
};

int main(){

return 0;
}