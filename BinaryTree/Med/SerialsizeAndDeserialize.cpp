#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=right=nullptr;
    }
};

class Solution {
  public:
    vector<int> serialize(Node* root) {
        vector<int> levelOrder;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node == nullptr)
                levelOrder.push_back(-1);
            else{
                levelOrder.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }
        }
        return levelOrder;
    }

    Node* deSerialize(vector<int>& arr) {
        if (arr.size() == 0 || arr[0] == -1) return nullptr;

        queue<Node*> q;
        int n = arr.size(),idx = 0;
        Node* root = new Node(arr[idx++]);
        q.push(root);

        while (!q.empty() && idx < n) {
            Node* node = q.front();
            q.pop();
            // Process left child
            if (idx < n) {
                int leftVal = arr[idx++];
                if (leftVal != -1) {
                    node->left = new Node(leftVal);
                    q.push(node->left);
                }
            }
            // Process right child
            if (idx < n) {
                int rightVal = arr[idx++];
                if (rightVal != -1) {
                    node->right = new Node(rightVal);
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};


int main(){

return 0;
}