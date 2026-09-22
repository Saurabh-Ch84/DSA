#include<bits/stdc++.h>
using namespace std;

// Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
    vector<int> helper(queue<Node*> &q,int sz){
        vector<int> nodes;
        while(sz--){
            Node* node=q.front(); q.pop();
            if(node->left){
                q.push(node->left);
                nodes.push_back(node->left->data);
            }
            if(node->right){
                q.push(node->right);
                nodes.push_back(node->right->data);
            }
        }
        return nodes;
    }
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        if(root1->data!=root2->data) return 0;
        
        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() && !q2.empty()){
            auto nodes1=helper(q1,q1.size());
            auto nodes2=helper(q2,q2.size());
            int n=nodes1.size(), m=nodes2.size();
            if(n!=m || !n || !m) break;
            sort(nodes1.begin(),nodes1.end());
            sort(nodes2.begin(),nodes2.end());
            int ptr=0;
            while(ptr<n){
                if(nodes1[ptr]!=nodes2[ptr]) return 0;
                ptr++;
            }
        }
        return (q1.empty() && q2.empty());
    }
};


int main(){

return 0;
}