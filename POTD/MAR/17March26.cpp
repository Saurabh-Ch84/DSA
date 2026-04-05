#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>

using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution1 {
    using memo_t=unordered_map<Node*,Node*>;
    Node*  preorder(Node* root,memo_t &parentMap,int target,Node* parent=nullptr){
        if(!root) return nullptr;
        parentMap[root]=parent;
        Node* ans=nullptr;
        if(root->data==target) ans=root;
        Node* leftSub=preorder(root->left,parentMap,target,root);
        Node* rightSub=preorder(root->right,parentMap,target,root);
        if(leftSub) ans=leftSub;
        else if(rightSub) ans=rightSub;
        return ans;
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        memo_t parentMap;
        Node* targetNode=preorder(root,parentMap,target);
        
        queue<Node*> q;
        q.push(targetNode);
        unordered_set<int> visitedSet;
        visitedSet.insert(targetNode->data);
        int timeReq=-1;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                Node* u=q.front(); q.pop();
                if(parentMap[u] && !visitedSet.count(parentMap[u]->data)){
                    q.push(parentMap[u]);
                    visitedSet.insert(parentMap[u]->data);
                }
                if(u->left && !visitedSet.count(u->left->data)){
                    q.push(u->left);
                    visitedSet.insert(u->left->data);
                }
                if(u->right && !visitedSet.count(u->right->data)){
                    q.push(u->right);
                    visitedSet.insert(u->right->data);
                }
            }
            timeReq++;
        }
        
        return timeReq;
    }
};


class Solution2 {
using vint=vector<int>;
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), maxi=0;

        vint row(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]) row[j]++;
                else row[j]=0;
            }
            vint temp=row;
            sort(temp.rbegin(),temp.rend());
            for(int j=0;j<m;j++){
                if(!temp[j]) break;
                maxi=max(maxi,temp[j]*(j+1));
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}