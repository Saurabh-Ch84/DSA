#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;
using vs = vector<string> ;

class Solution {
    bool canFollow(int prev,int j,int n,vs &strs){  
        for(int i=0;i<n;i++){
            if(strs[i][prev]>strs[i][j]) return false;
        }
        return true;
    }

    int recursion(int j,int n,int m,vs &strs,int prev,vvi &dp){
        if(j>=m) return 0;
        if(dp[j][prev+1]!=-1) return dp[j][prev+1];
        int notTake = recursion(j+1,n,m,strs,prev,dp);
        int take=0;
        if(prev==-1 || canFollow(prev,j,n,strs))
            take = 1 + recursion(j+1,n,m,strs,j,dp);
        return dp[j][prev+1]=max(notTake,take);
    }

public:
    int minDeletionSize(vs &strs) {
        int n=strs.size(), m=strs[0].size();
        vvi dp(m,vi(m+1,-1));
        return m-recursion(0,n,m,strs,-1,dp);
    }
};

int main(){

return 0;
}