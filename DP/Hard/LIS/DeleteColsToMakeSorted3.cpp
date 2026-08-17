#include<iostream>
#include<vector>
using namespace std;


class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vstr=vector<string>;
    bool isValid(vstr &strs,int p,int j,int n){
        for(int i=0;i<n;i++){
            if(strs[i][p]>strs[i][j])
                return false;
        }
        return true;
    }
    int recursion(int j,int p,int n,int m,vstr &strs,vvint &dp){
        if(j==m) return 0;
        if(dp[j][p+1]!=-1) return dp[j][p+1];
        int notTake=recursion(j+1,p,n,m,strs,dp), take=0;
        if(p==-1 || isValid(strs,p,j,n))
            take=1+recursion(j+1,j,n,m,strs,dp);
        return dp[j][p+1]=max(take,notTake);
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(), m=strs[0].size();
        vvint dp(m+1,vint(m+1,-1));
        int globalLIS=recursion(0,-1,n,m,strs,dp);
        return m-globalLIS;
    }
};

int main(){

return 0;
}