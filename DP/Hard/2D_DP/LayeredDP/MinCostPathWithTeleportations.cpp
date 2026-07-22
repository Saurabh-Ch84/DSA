#include<iostream>
#include<vector>
#include<climits>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
    const int inf=INT_MAX;
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vvi dp(n,vi(m,inf));
        dp[n-1][m-1]=0;
        int maxVal=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                maxVal=max(maxVal,grid[i][j]);
        }

        vi teleport(maxVal+1,inf);
        for(int t=0;t<=k;t++){
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(i+1<n){
                        dp[i][j]=min(dp[i][j],grid[i+1][j]+dp[i+1][j]);
                    }
                    if(j+1<m){
                        dp[i][j]=min(dp[i][j],grid[i][j+1]+dp[i][j+1]);
                    }
                    if(t>0){
                        dp[i][j]=min(dp[i][j],teleport[grid[i][j]]);
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    teleport[grid[i][j]]=min(teleport[grid[i][j]],dp[i][j]);
                }
            }
            for(int i=1;i<maxVal+1;i++){
                teleport[i]=min(teleport[i],teleport[i-1]);
            }
        }
        return dp[0][0];
    }
};

int main(){

return 0;
}