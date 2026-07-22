#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vector<int>> ;
using vvvi = vector<vector<vector<int>>> ;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && i>=0 && j<m && j>=0);
    }
    int memoization(int i,int j,int n,int m,int k,vvi &mat,vvvi &dp){
        int coins=mat[i][j];
        if(i==n-1 && j==m-1) return (coins==k);
        if(k<0) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ways=0;
        vi di={1,0},dj={0,1};
        for(int l=0;l<2;l++){
            int i_=i+di[l],j_=j+dj[l];
            if(!isValid(i_,j_,n,m)) continue;
            ways+=memoization(i_,j_,n,m,k-coins,mat,dp);
        }
        return dp[i][j][k]=ways;
    }
  public:
    int numberOfPath(vvi &mat, int k) {
        // Code Here
        int n=mat.size(),m=mat[0].size();
        vvvi dp(n,vvi(m,vi(k+1,-1)));
        return memoization(0,0,n,m,k,mat,dp);
    }
};

int main(){

return 0;
}