#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int>;
class Solution {
    int recursion(int n,vi &dp){
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        int half=n/2;
        int half_=n-n/2;
        return  dp[n]=(half*half_)+(recursion(half,dp)+recursion(half_,dp));
    }
public:
    int minCost(int n){
        vi dp(n+1,-1);
        return recursion(n,dp);
    }
};

int main(){

return 0;
}