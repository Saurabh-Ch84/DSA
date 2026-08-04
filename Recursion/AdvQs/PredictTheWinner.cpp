#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    int inf=1e9;
    int recursion(int i,int j,vint &nums,vvvint &dp,bool turn=1){
        if(i>j) return 0;
        if(dp[i][j][turn]!=inf) return dp[i][j][turn];
        int score=0;
        if(turn){
            int takeLeft=nums[i]+recursion(i+1,j,nums,dp,0);
            int takeRight=nums[j]+recursion(i,j-1,nums,dp,0);
            score=max(takeLeft,takeRight);
        }
        else{
            int takeLeft=-nums[i]+recursion(i+1,j,nums,dp,1);
            int takeRight=-nums[j]+recursion(i,j-1,nums,dp,1);
            score=min(takeLeft,takeRight);
        }
        return dp[i][j][turn]=score;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vvvint dp(n,vvint(n,vint(2,inf)));
        recursion(0,n-1,nums,dp);
        return (dp[0][n-1][1]>=0);
    }
};

class Solution2 {
    using vint = vector<int>;
    using vvint = vector<vint>;
    int inf = 1e9;
    
    int recursion(int i, int j, vint &nums, vvint &dp) {
        if (i > j) return 0;
        if (dp[i][j] != inf) return dp[i][j];
        // The Min-Max Trick: 
        // Score = My chosen stone MINUS the best relative score the opponent can get from the remaining stones.
        int takeLeft = nums[i] - recursion(i + 1, j, nums, dp);
        int takeRight = nums[j] - recursion(i, j - 1, nums, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vvint dp(n, vint(n, inf)); // Reduced from 3D to 2D
        // If the max relative score difference is >= 0, Player 1 wins/ties.
        return recursion(0, n - 1, nums, dp) >= 0;
    }
};

int main(){

return 0;
}