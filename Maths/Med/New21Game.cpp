#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    double recursion(int n,int k,int maxPts,int sum,double p,unordered_map<int,double> &dp){
        if(k<=sum && sum<=n) return 1.0;
        if(k<=sum) return 0.0;
        if(dp.count(sum)) return dp[sum];
        double ans=0.0;
        for(int i=1;i<=maxPts;i++)
            ans+=p*recursion(n,k,maxPts,sum+i,p,dp);
        return dp[sum]=ans;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        unordered_map<int,double> dp;
        double probability=recursion(n,k,maxPts,0,1.0/(double)maxPts,dp);
        return probability;
    }
};

int main(){

return 0;
}