#include<iostream>
#include<vector>
#include<climits>
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
    using vint=vector<int>;
    
    vint isBST(Node* root){
        if(!root) return {INT_MAX,INT_MIN,0};
        vint leftSub=isBST(root->left);
        vint rightSub=isBST(root->right);
        
        if(root->data>leftSub[1] && root->data<rightSub[0]){
            return {min(root->data,leftSub[0]),
                    max(root->data,rightSub[1]),
                    (leftSub[2]+rightSub[2]+1)};
        }
        return {INT_MIN,INT_MAX,max(leftSub[2],rightSub[2])};
    }
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        return isBST(root)[2];
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), count=0;
        vvint temp(m,vint(3,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='.') temp[j][0]++;
                else if(grid[i][j]=='X') temp[j][1]++;
                else temp[j][2]++;
            }
            vint row(3,0);
            for(int j=0;j<m;j++){
                for(int k=0;k<3;k++)
                    row[k]=row[k]+temp[j][k];
                if(row[1] && row[1]==row[2])
                    count++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}