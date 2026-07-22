#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<int> printCousins(Node* root, Node* node_to_find) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool isNodeFound=false;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* node=q.front();
                q.pop();
                if(node->left==node_to_find || node->right==node_to_find){
                    isNodeFound=true;
                    continue;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(isNodeFound) break;
        }
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};

int main(){

return 0;
}