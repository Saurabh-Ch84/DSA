#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left,*right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        ans.push_back(root->data);
        int level=0;
        while(!q.empty()){
            int size=q.size(),arraySize=ans.size();
            level++;
            for(int i=0;i<size;i++)
            {
                Node *node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    ans.push_back(node->left->data);
                }
                if(node->right){
                    q.push(node->right);
                    ans.push_back(node->right->data);
                }
            }
            if(level%2) reverse(ans.begin()+arraySize,ans.end());
        }
        return ans;
    }
};

int main(){

return 0;
}