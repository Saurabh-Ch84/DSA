#include<bits/stdc++.h>
using namespace std;

// Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
    bool isLeaf(Node* u){
        return (!u->left && !u->right);
    }
  public:
    int getCount(Node *root, int k) {
        // code here
        if(!root) return 0;
        int total=0, level=1;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            if(level>k) break;
            int sz=q.size(), curr=0;
            while(sz--){
                Node* u=q.front(); q.pop();
                if(isLeaf(u) && k>=level){
                    curr++;
                    k-=level;
                    continue;
                }
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            total=total+curr;
            level++;
        }
        return total;
    }
};

int main(){

return 0;
}