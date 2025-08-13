#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
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

int main(){

return 0;
}