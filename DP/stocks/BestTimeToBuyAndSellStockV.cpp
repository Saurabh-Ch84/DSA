#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

class Solution {
    long long recursion(int i,int n,int k,vi &prices,int turn,vvvll &dp){
        if(i>=n || k<=0){
            if(!turn) return 0;
            return 1LL*-1e12;
        }
        if(dp[i][k][turn]!=-1) return dp[i][k][turn];
        long long result=-1e12;
        if(!turn){
            long long normalBuy=-prices[i]+recursion(i+1,n,k,prices,1,dp);
            long long normalWeight=recursion(i+1,n,k,prices,0,dp);
            result=max({result,normalBuy,normalWeight});

            long long shortBuy=prices[i]+recursion(i+1,n,k,prices,2,dp);
            long long shortWeight=recursion(i+1,n,k,prices,0,dp);
            result=max({result,shortBuy,shortWeight});
        }
        else if(turn==1){
            long long normalSell=prices[i]+recursion(i+1,n,k-1,prices,0,dp);
            long long normalWeight=recursion(i+1,n,k,prices,1,dp);
            result=max({result,normalSell,normalWeight});
        }
        else{
            long long shortSell=-prices[i]+recursion(i+1,n,k-1,prices,0,dp);
            long long shortWeight=recursion(i+1,n,k,prices,2,dp);
            result=max({result,shortSell,shortWeight});
        }
        return dp[i][k][turn]=result;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        vvvll dp(n,vvll(k+1,vll(3,-1)));
        return recursion(0,n,k,prices,0,dp);
    }
};

int main(){

return 0;
}