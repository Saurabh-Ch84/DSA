#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        
        // Iterate through all parent nodes
        // The last parent is at index (n/2) - 1
        for (int p = 0; p <= (n / 2) - 1; p++) {
            int left = 2 * p + 1, right = 2 * p + 2;
            // Check left child
            if (left < n && arr[p] < arr[left]) {
                return false;
            }
            // Check right child
            if (right < n && arr[p] < arr[right]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    int recursion(int i,int j,int k,int m,int n,vvint &grid,vvvint &dp){
        int cost=(grid[i][j]? 1:0);
        if(i==m-1 && j==n-1){
            return (cost>k? -1e7: grid[i][j]);
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int right=-1e7, down=-1e7;
        if(k>=cost){
            if(j<n-1) right=grid[i][j]+recursion(i,j+1,k-cost,m,n,grid,dp);
            if(i<m-1) down=grid[i][j]+recursion(i+1,j,k-cost,m,n,grid,dp);
        }
        return dp[i][j][k]=max(right,down);
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vvvint dp(m+1,vvint(n+1,vint(k+1,-1)));
        int ans=recursion(0,0,k,m,n,grid,dp);
        return (ans<0? -1: ans);
    }
};

int main(){

return 0;
}