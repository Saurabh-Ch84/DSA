#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    vector<bool> sieve(int n){
        vector<bool> primes(n+1,true);
        primes[0]=primes[1]=false;
        int x=sqrt(n);
        for(int i=2;i<=x;i++){
            if(primes[i])
                for(int j=i*i;j<=n;j+=i) primes[j]=false;
        }
        return primes;
    }
    void precompute(unordered_map<int,vector<int>> &adjM,int n){
        vector<bool> primes=sieve(2*n);
        for(int i=0;i<n;i++){
            if(primes[i]){
                adjM[-1].push_back(i);
                for(int j=i;j<n;j++){
                    if(primes[j]){
                        int sum=i+j;
                        if(primes[sum]==false){
                            adjM[i].push_back(j);
                            if(i==j) continue;
                            adjM[j].push_back(i);
                        }
                    }
                }
            }
        }
    }
    int DFS(TreeNode* root,unordered_map<int,vector<int>> &adjM,int parent,
            unordered_map<TreeNode*,unordered_map<int,int>> &dp){
        if(!root) return 1;
        if(dp[root][parent]) return dp[root][parent];
        int totalWays = 0;
        for(int &primeVal : adjM[parent]){
            int leftWays  = DFS(root->left, adjM, primeVal,dp);
            int rightWays = DFS(root->right, adjM, primeVal,dp);
            totalWays += leftWays * rightWays;
        }   
        return dp[root][parent]=totalWays;
    }
        public:
    int countWays(int n,TreeNode* root){
        unordered_map<int,vector<int>> adjM;
        precompute(adjM,n);
        unordered_map<TreeNode*,unordered_map<int,int> > dp;
        return DFS(root,adjM,-1,dp);
    }
};

int main(){
    Solution s;
    TreeNode* root=new TreeNode(0);
    root->left=new TreeNode(1);
    root->right=new TreeNode(2);
    // root->right->right=new TreeNode(3);
    cout<<s.countWays(100,root);
    delete root;
return 0;
}