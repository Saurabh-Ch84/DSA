#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// A binary tree node

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


//DFS more efficient
class Solution1 {
    void DFS(Node *root,vector<int> &ds,int level=0){
        if(!root) return ;
        if(level==ds.size()) ds.push_back(root->data);
        DFS(root->left,ds,level+1);
        DFS(root->right,ds,level+1);
    }
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> left;
        DFS(root,left);
        return left;
    }
};

class Solution2 {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(!root) return {};
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        res.push_back(root->data);
        
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++){
                Node *node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    flag=true;
                }
                if(node->right){
                    q.push(node->right);
                    flag=true;
                }
            }
            if(flag) res.push_back(q.front()->data);
        }
        return res;
    }
};

int main(){

return 0;
}