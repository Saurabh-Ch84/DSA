#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int>;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prevPrev=0,prev=0;
        for(int i=0;i<n;i++){
            int costToReach=cost[i]+min(prevPrev,prev);
            prevPrev=prev;
            prev=costToReach;
        }
        return min(prevPrev,prev);
    }
};

class Solution {
    int recursion(int i,int n,vector<int> &cost,vi &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1)  return dp[i];
        int c=cost[i];
        int oneStep=c+recursion(i+1,n,cost,dp);
        int twoStep=c+recursion(i+2,n,cost,dp);
        return dp[i]=min(oneStep,twoStep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vi dp(n,-1);
        int startFromZero=recursion(0,n,cost,dp);
        int startFromOne=recursion(1,n,cost,dp);
        return min(startFromZero,startFromOne);
    }
};

int main(){

return 0;
}