#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        
        vector<vector<long long>> dp;
        transform(obstacleGrid.begin(), obstacleGrid.end(), back_inserter(dp), [](const vector<int>& row) {
            return vector<long long>(row.begin(), row.end());
        });    
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 || j==n-1)                
                {
                    if(i==m-1 && j==n-1)    
                    {
                        dp[i][j]=1;
                    }
                    else if(i==m-1)
                    {
                        if(dp[i][j]==1)
                            dp[i][j]=0;
                        else
                        dp[i][j]=dp[i][j+1];    
                    }
                    else
                    {
                        if(dp[i][j]==1)
                            dp[i][j]=0;
                        else
                            dp[i][j]=dp[i+1][j]; 
                    }
                }
                else
                {
                    if(dp[i][j]==1)
                        dp[i][j]=0;
                    else
                        dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};

int main(){

return 0;
}