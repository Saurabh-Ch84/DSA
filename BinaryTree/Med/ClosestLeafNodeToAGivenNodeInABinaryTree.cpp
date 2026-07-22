#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    void makeGraph(Node* root,unordered_map<Node*,Node*> &hashMap){
        if(!root) return ;
        if(root->left) hashMap[root->left]=root;
        if(root->right) hashMap[root->right]=root;
        makeGraph(root->left,hashMap);
        makeGraph(root->right,hashMap);
    }

    bool isLeaf(Node* node){
        return node && !node->left && !node->right;
    }

    int BFS(Node* root,unordered_map<Node*,Node*> &hashMap){
        unordered_set<Node*> hashSet;
        queue<Node*> q;
        q.push(root);
        hashSet.insert(root);

        int distance=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* node=q.front();
                q.pop();
                if(isLeaf(node)) return distance;
                if(hashMap.count(node) && hashSet.insert(hashMap[node]).second)
                    q.push(hashMap[node]);
                if(node->left && hashSet.insert(node->left).second) 
                    q.push(node->left);
                if(node->right && hashSet.insert(node->right).second) 
                    q.push(node->right);
            }
            distance++;
        }
        return -1; //dummy return
    }
        public:
    int closestLeafDist(Node* root,Node* node){
        unordered_map<Node*,Node*> hashMap;
        makeGraph(root,hashMap);
        return BFS(node,hashMap);
    }
};

int main(){
     /*
        Construct the following tree:
               1
             /   \
            2     3
           /     / \
          4     5   6
                   /
                  7
        Closest leaf distances for nodes:
        - Node 1: closest leaf is 4 or 5 at distance 2
        - Node 3: closest leaf is 5 or 7 at distance 1
        - Node 6: closest leaf is 7 at distance 1
        - Node 4: itself a leaf, distance 0
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    Solution sol;

    cout << "Closest leaf distance to node 1: " << sol.closestLeafDist(root, root) << "\n";
    cout << "Closest leaf distance to node 3: " << sol.closestLeafDist(root, root->right) << "\n";
    cout << "Closest leaf distance to node 6: " << sol.closestLeafDist(root, root->right->right) << "\n";
    cout << "Closest leaf distance to node 4: " << sol.closestLeafDist(root, root->left->left) << "\n";
return 0;
}