#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    int levelOrder(Node *root,unordered_map<int,int> &xMap)
    {
        int minLevel=INT_MAX;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node *node=q.front().first;
                int level=q.front().second;
                q.pop();
                if(xMap.find(level)==xMap.end()) xMap[level]=node->data;
                if(node->left) q.push({node->left,level-1});
                if(node->right) q.push({node->right,level+1});
                minLevel=min(minLevel,level);
            }
        }
        return minLevel;
    }
    vector<int> topView(Node *root) {
        // code here
        unordered_map<int,int> verticalMap;
        int minLevel=levelOrder(root,verticalMap);

        int size=verticalMap.size();
        vector<int> topView(size);
        for(auto &p:verticalMap){
            int level=p.first;
            int actualLevel=level-minLevel;
            topView[actualLevel]=p.second;
        }
        return topView;
    }
};

int main(){

return 0;
}