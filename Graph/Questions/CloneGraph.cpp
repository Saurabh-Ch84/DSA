#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    Node* DFS(Node* node,unordered_map<Node* ,Node*> &hashMap){
        if(node==nullptr) return nullptr;
        if(hashMap.find(node)!=hashMap.end()) 
            return hashMap[node];
        Node* newNode=new Node(node->val);
        hashMap[node]=newNode;
        for(Node* itr:node->neighbors){
            Node* newNeighborNode=DFS(itr,hashMap);
            newNode->neighbors.push_back(newNeighborNode);
        }
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> hashMap;
        return DFS(node,hashMap);
    }
};

int main(){

return 0;
}