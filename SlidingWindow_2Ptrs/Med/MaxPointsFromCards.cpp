#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int recursion(vector<int>& cardPoints,int i,int n,int k,vector<vector<vector<int>>> &dp){
        if(k==0) return 0;
        if(i>n) return 0;
        if(dp[i][n][k]!=-1) return dp[i][n][k];
        int points=0;
        int takeLeft=cardPoints[i]+recursion(cardPoints,i+1,n,k-1,dp);
        int takeRight=cardPoints[n]+recursion(cardPoints,i,n-1,k-1,dp);
        return dp[i][n][k]=max(takeLeft,takeRight);
    }
public:
    int maxScore2(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return recursion(cardPoints,0,cardPoints.size()-1,k,dp);
    }
        // Optimal Approach
    int maxScore(vector<int>& cardPoints, int k) {
        int maxSum=0,leftSum=0,rightSum=0,n=cardPoints.size();
        
        for(int j=0;j<k;j++) leftSum+=cardPoints[j];
        maxSum=leftSum;

        for(int i=0;i<k;i++){
            rightSum+=cardPoints[n-i-1];
            leftSum-=cardPoints[k-i-1];
            maxSum=max(leftSum+rightSum,maxSum);
        }
        return maxSum;
    }
};

int main(){

return 0;
}