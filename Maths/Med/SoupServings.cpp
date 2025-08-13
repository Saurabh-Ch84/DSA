#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

class Solution {
    double memoization(int i,int j,unordered_map<int,unordered_map<int,double>> &dp){
        if(i<=0 && j<=0) return 0.5;
        if(i<=0) return 1.0;
        if(j<=0) return 0.0;
        if(dp[i].count(j)) return dp[i][j];
        return dp[i][j]=0.25*(memoization(i-4,j,dp)+memoization(i-3,j-1,dp)+
                              memoization(i-2,j-2,dp)+memoization(i-1,j-3,dp));
    }
public:
    double soupServings(int n) {
        if(n==0) return 0.5;
        int totalServings=ceil(n/25.0);
        double probability;
        unordered_map<int,unordered_map<int,double>> dp;
        for(int serve=1;serve<=totalServings;serve++){
            probability=memoization(serve,serve,dp);
            if(probability>1-(1e-5)) return 1.0;
        }
        return probability;
    }
};

int main(){

return 0;
}