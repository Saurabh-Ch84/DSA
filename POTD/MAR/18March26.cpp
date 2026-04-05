#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size(), count=0;
        vint temp(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                temp[j]=temp[j]+grid[i][j];
            if(temp[0]>k) break;
            int sum=0;
            for(int i=0;i<m;i++){
                sum=sum+temp[i];
                if(sum<=k) count++;
                else break;
            }
        }
        return count;
    }
};

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
    int postOrder(Node* root,int &moves){
        if(!root) return 0;
        int leftExcess=postOrder(root->left,moves);
        int rightExcess=postOrder(root->right,moves);
        moves=moves+abs(leftExcess)+abs(rightExcess);
        return leftExcess+rightExcess+root->data-1;
    }
  public:
    int distCandy(Node* root) {
        // code here
        int moves=0;
        postOrder(root,moves);
        return moves;
    }
};

int main(){

return 0;
}