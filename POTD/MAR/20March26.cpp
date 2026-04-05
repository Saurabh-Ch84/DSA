#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
    class BST_iterator{
        stack<Node*> st;
        void fillStack(Node* root){
            if(!root) return ;
            st.push(root);
            while(root->left){
                st.push(root->left);
                root=root->left;
            }
        }
            public: 
        BST_iterator(Node* root){
            fillStack(root);
        }
        
        bool isEmpty(){
            return st.empty();
        }
        
        Node* top(){
            Node* temp=st.top();
            st.pop();
            fillStack(temp->right);
            return temp;
        }
    };
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        BST_iterator bst(root);
        
        int preDiff=1e9, succDiff=1e9;
        Node *pre=nullptr, *succ=nullptr;
        while(!bst.isEmpty()){
            Node* node=bst.top();
            if(node->data<key && key-node->data<preDiff){
                preDiff=key-node->data;
                pre=node;
            }
            else if(node->data>key && node->data-key<succDiff){
                succDiff=node->data-key;
                succ=node;
            }
        }
        
        return {pre,succ};
    }
};

class Solution {
    int getMinAbsDiff(set<int> &s){
        int mini=1e9, prev=-1e9;
        for(auto it=s.begin();it!=s.end();it++){
            if(prev!=-1e9) mini=min(mini,abs(prev-*it));
            prev=*it;
        }
        return mini;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,0));
        if(k==1) return ans;
    
        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                set<int> subMatSet;
                for(int i_=i;i_<i+k;i_++){
                    for(int j_=j;j_<j+k;j_++)
                        subMatSet.insert(grid[i_][j_]);
                }
                if(subMatSet.size()==1) continue;
                ans[i][j]=getMinAbsDiff(subMatSet);
            }
        }
        return ans;
    }
};

int main(){

return 0;
}