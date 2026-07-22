#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vector<int>> ;
using vvvi = vector<vector<vector<int>>> ;
using vvvvi = vector<vector<vector<vector<int>>>> ;

class Solution1 {
    bool isValid(int i,int j,int n){
        return (i>=0 && i<n && j>=0 && j<n);
    }
    int recursion(int i1,int j1,int i2,int j2,int n,vvi &mat,vvvvi &dp){
        if(mat[i1][j1]==-1 || mat[i2][j2]==-1) return -1e6;
        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        int curr=mat[i1][j1]+(i1==i2 && j1==j2 ? 0: mat[i2][j2]);
        if(i1==i2 && j1==j2 && i1==n-1 && j1==n-1) return curr;
        int maxi=-1e6;
        vi di={0,1},dj={1,0};
        for(int k1=0;k1<2;k1++){
            int i1_=i1+di[k1],j1_=j1+dj[k1];
            if(!isValid(i1_,j1_,n)) continue;
            for(int k2=0;k2<2;k2++){
                int i2_=i2+di[k2],j2_=j2+dj[k2];
                if(!isValid(i2_,j2_,n)) continue;
                int next=curr+recursion(i1_,j1_,i2_,j2_,n,mat,dp);
                maxi=max(maxi,next);
            }
        }
        return dp[i1][j1][i2][j2]=maxi;
    }
  public:
    int chocolatePickup(vvi &mat) {
        // code here
        int n=mat.size();
        vvvvi dp(n,vvvi(n,vvi(n,vi(n,-1))));
        int result=recursion(0,0,0,0,n,mat,dp);
        return max(0,result);
    }
};

class Solution2 {
    bool isValid(int i, int j, int n) {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    int recursion(int i1, int j1, int i2, int n, vvi &mat,vvvi &dp) {
        
        // Calculate j2 from the other 3 state variables
        int j2 = i1 + j1 - i2;

        // 1. Base Case: Out of bounds or hit a thorn
        // We must check validity for *both* P1 and P2
        if (!isValid(i1, j1, n) || !isValid(i2, j2 ,n) || mat[i1][j1] == -1 || mat[i2][j2] == -1) {
            return -1e9; // Use a large negative number for invalid paths
        }

        if (i1 == n - 1 && j1 == n - 1) {
            return mat[i1][j1];
        }

        // 3. Memoization Check
        if (dp[i1][j1][i2] != -1) {
            return dp[i1][j1][i2];
        }

        // 4. Calculate current chocolates
        int curr = mat[i1][j1];
        if (i1 != i2 || j1 != j2) {
            curr += mat[i2][j2];
        }

        // 5. Explore all 4 possible *next* moves
        int maxi = -1e9;
        
        // (P1-Down, P2-Down)
        maxi = max(maxi, recursion(i1 + 1, j1, i2 + 1, n, mat, dp)); 
        // (P1-Down, P2-Right)
        maxi = max(maxi, recursion(i1 + 1, j1, i2, n, mat, dp));
        // (P1-Right, P2-Down)
        maxi = max(maxi, recursion(i1, j1 + 1, i2 + 1, n, mat, dp));
        // (P1-Right, P2-Right)
        maxi = max(maxi, recursion(i1, j1 + 1, i2, n, mat, dp));

        // 6. Store and return the result
        return dp[i1][j1][i2] = curr + maxi;
    }

  public:
    int chocolatePickup(vvi &mat) {
        int n = mat.size();
        vvvi dp;
        dp.assign(n, vvi(n, vi(n, -1)));
        int result = recursion(0, 0, 0, n, mat, dp);
        return max(0, result);
    }
};

int main(){

return 0;
}