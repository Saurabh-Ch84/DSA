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

class Solution1 {
    // optimal
    Node* getLCA(Node* root,int p,int q){
        if(!root || root->data==p || root->data==q) return root;
        Node* left=getLCA(root->left,p,q);
        Node* right=getLCA(root->right,p,q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
    bool DFS(Node* src,int dest,string &path){
        if(!src) return 0;
        if(src->data==dest) return 1;
        path.push_back('0');
        if(DFS(src->left,dest,path))
            return 1;
        path.pop_back();
        path.push_back('1');
        if(DFS(src->right,dest,path))
            return 1;
        path.pop_back();
        return 0;
    }
  public:
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        // SW-0, SE-1
        Node* lca=getLCA(root,p,q);
        string path;
        DFS(lca,p,path);
        reverse(path.begin(),path.end());
        DFS(lca,q,path);
        int n=path.size(), count=0;
        for(int i=0;i<n-1;i++){
            if(path[i]!=path[i+1])
                count++;
        }
        return (count? count:-1);
    }
};

class Solution2 {
    // brute force.
    unordered_map<Node*,pair<Node*,int>> parentMap; 
    void DFS(Node* node,Node* &src,int p,Node* parent=nullptr,int d=-1){ 
        if(!node) return ;
        if(parent) parentMap[node]={parent,d};
        if(!src && node->data==p) src=node;
        DFS(node->left,src,p,node,3);
        DFS(node->right,src,p,node,2);
    }
  public:
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        // NW-0, NE-1, SE-2, SW-3
        Node* src=nullptr;
        DFS(root,src,p);

        queue<pair<Node*,pair<int,int>>> Q;
        Q.push({src,{-1,0}});
        unordered_set<Node*> visited;
        visited.insert(src);

        while(!Q.empty()){
            pair<Node*,pair<int,int>> entry=Q.front(); Q.pop();
            Node* node=entry.first;
            int direction=entry.second.first, turns=entry.second.second;
            if(node->data==q) return (turns? turns:-1);
            if(node->left && !visited.count(node->left)){
                if(direction==3 || direction==-1) Q.push({node->left,{3,turns}});
                else Q.push({node->left,{3,turns+1}});
                visited.insert(node->left);
            }
            if(node->right && !visited.count(node->right)){
                if(direction==2 || direction==-1) Q.push({node->right,{2,turns}});
                else Q.push({node->right,{2,turns+1}});
                visited.insert(node->right);
            }
            if(parentMap.count(node) && !visited.count(parentMap[node].first)){
                Node* parent=parentMap[node].first;
                int direction_=parentMap[node].second;
                if(direction_==direction || direction==-1) Q.push({parent,{direction_,turns}});
                else Q.push({parent,{direction_,turns+1}});
                visited.insert(parent);
            }
        }
        return -2; // dummy return 
    }
};

int main(){

return 0;
}