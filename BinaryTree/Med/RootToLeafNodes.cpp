#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    void DFS(Node* root,vector<int> &path,vector<vector<int>> &allPaths){
        if(!root) return ;
        path.push_back(root->data);
        DFS(root->left,path,allPaths);
        DFS(root->right,path,allPaths);
        if(!root->left && !root->right)
            allPaths.push_back(path);
        path.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> path;
        vector<vector<int>> allPaths;
        DFS(root,path,allPaths);
        return allPaths;
    }
};

int main(){

return 0;
}