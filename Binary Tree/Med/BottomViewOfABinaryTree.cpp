#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution1 {
    int levelOrder(Node *root,unordered_map<int,int> &xMap){
        int minLevel=INT_MAX;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *node=q.front().first;
                int level=q.front().second;
                q.pop();
                xMap[level]=node->data;
                if(node->left) q.push({node->left,level-1});
                if(node->right) q.push({node->right,level+1});
                minLevel=min(minLevel,level);
            }
        }
        return minLevel;
    }
    public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        unordered_map<int,int> hashMap;
        int minLevel=levelOrder(root,hashMap);
        vector<int> bottom(hashMap.size());
        for(auto &p:hashMap){
            int level=p.first;
            int val=p.second;
            int actualLevel=level-minLevel;
            bottom[actualLevel]=val;
        }
        return bottom;
    }
};

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


using pNi=pair<Node*,int>;
class Solution2 {
    
    int BFS(Node *root,unordered_map<int,int> &hashMap){
        
        queue<pNi> q;
        q.push({root,0});
        int mini=INT_MAX;
        while(!q.empty()){
            pNi p=q.front();
            q.pop();
            Node* node=p.first;
            int level=p.second;
            hashMap[level]=node->data;
            if(node->left){
                q.push({node->left,level-1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
            mini=min(mini,level);
        }
        return mini;
    }
    
  public:
    vector<int> bottomView(Node *root) {
        // code here
        unordered_map<int,int> hashMap;
        int mini=BFS(root,hashMap);
        vector<int> res(hashMap.size());
        
        for(auto &p:hashMap){
            int level=p.first,val=p.second;
            int idx=level-mini;
            res[idx]=val;
        }
        
        return res;
    }
};

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

using pNi=pair<Node*,int>;

class Solution3 {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        queue<pNi> q;
        map<int,int> map_;
        q.push({root,0});
        
        while(!q.empty()){
            pNi p=q.front();
            q.pop();
            Node* node=p.first;
            int level=p.second;
            map_[level]=node->data;
            if(node->left){
                q.push({node->left,level-1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }
        
        vector<int> res;
        for(auto& p:map_){
            int val=p.second;
            res.push_back(val);
        }
        
        return res;
    }
};

int main(){

return 0;
}