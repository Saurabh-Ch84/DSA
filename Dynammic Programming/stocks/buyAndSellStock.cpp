#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int memoization(vector<int> &p,int m,int i,int buy,int trans,vector<vector<vector<int>>> &dp){
        if(i==m || trans==0) return 0;
        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
        int profit=0;
        if(buy){
            int buyStock=-p[i]+memoization(p,m,i+1,0,trans,dp);
            int dontBuyStock=memoization(p,m,i+1,1,trans,dp);
            profit=max(buyStock,dontBuyStock);
        }
        else{
            int sellStock=p[i]+memoization(p,m,i+1,1,trans-1,dp);
            int dontSellStock=0+memoization(p,m,i+1,0,trans,dp);
            profit=max(sellStock,dontSellStock);
        }
        return dp[i][buy][trans]=profit;
    }
    int memoizationMod(vector<int>& prices,int idx,int m,int transactions,vector<vector<int>> &dp){
        if(idx==m || transactions==4) return 0;
        if(dp[idx][transactions]!=-1) return dp[idx][transactions];
        int profit=0;
        if(transactions%2==0){
            int buyStock=-prices[idx]+memoizationMod(prices,idx+1,m,transactions+1,dp);
            int dontBuyStock=0+memoizationMod(prices,idx+1,m,transactions,dp);
            profit=max(buyStock,dontBuyStock);
        }
        else{
            int sellStock=prices[idx]+memoizationMod(prices,idx+1,m,transactions+1,dp);
            int dontSellStock=0+memoizationMod(prices,idx+1,m,transactions,dp);
            profit=max(sellStock,dontSellStock);
        }
        return dp[idx][transactions]=profit;
    }
public:
    int maxProfit4memo(int k, vector<int>& prices) {
        int m=prices.size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return memoization(prices,m,0,1,k,dp);
    }
    int maxProfit3tab(vector<int>& prices) {
        int m=prices.size();
        // vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(2,vector<int>(3,0)));
        // for(int idx=m-1;idx>=0;idx--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int transactions=1;transactions<=2;transactions++){
        //             if(buy){
        //                 int buyStock=-prices[idx]+dp[idx+1][0][transactions];
        //                 int dontBuyStock=0+dp[idx+1][1][transactions];
        //                 dp[idx][buy][transactions]=max(buyStock,dontBuyStock);
        //             }
        //             else{
        //                 int sellStock=prices[idx]+dp[idx+1][1][transactions-1];
        //                 int dontSellStock=0+dp[idx+1][0][transactions];
        //                 dp[idx][buy][transactions]=max(sellStock,dontSellStock);
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][2];
        // vector<vector<int>> dp(m,vector<int>(4,-1));
        // return memoizationMod(prices,0,m,0,dp);

        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));

        for(int idx=m-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int transactions=1;transactions<=2;transactions++){
                    if(buy){
                        int buyStock=-prices[idx]+after[0][transactions];
                        int dontBuyStock=0+after[1][transactions];
                        curr[buy][transactions]=max(buyStock,dontBuyStock);
                    }
                    else{
                        int sellStock=prices[idx]+after[1][transactions-1];
                        int dontSellStock=0+after[0][transactions];
                        curr[buy][transactions]=max(sellStock,dontSellStock);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];
    }
    int maxProfit4Tab(int k, vector<int>& prices) {
        int m=prices.size();
        // vector<vector<vector<int>>> dp(m,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return memoization(prices,m,0,1,k,dp);
        // vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        // for(int i=m-1;i>-1;i--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int trans=1;trans<=k;trans++){
        //             if(buy){
        //                 int buyStock=-prices[i]+dp[i+1][0][trans];
        //                 int dontBuyStock=dp[i+1][1][trans];
        //                 dp[i][buy][trans]=max(buyStock,dontBuyStock);
        //             }
        //             else{
        //                 int sellStock=prices[i]+dp[i+1][1][trans-1];
        //                 int dontSellStock=0+dp[i+1][0][trans];
        //                 dp[i][buy][trans]=max(sellStock,dontSellStock);
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][k];

        // vector<vector<int>> after(2,vector<int>(k+1,0));
        // vector<vector<int>> curr(2,vector<int>(k+1,0));

        // for(int i=m-1;i>-1;i--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int trans=1;trans<=k;trans++){
        //             if(buy){
        //                 int buyStock=-prices[i]+after[0][trans];
        //                 int dontBuyStock=after[1][trans];
        //                 curr[buy][trans]=max(buyStock,dontBuyStock);
        //             }
        //             else{
        //                 int sellStock=prices[i]+after[1][trans-1];
        //                 int dontSellStock=0+after[0][trans];
        //                 curr[buy][trans]=max(sellStock,dontSellStock);
        //             }
        //         }
        //     }
        //     after=curr;
        // }
        // return after[1][k];
        vector<int> after(5,0);
        vector<int> curr(5,0);
        for(int i=m-1;i>-1;i--){
            for(int transactions=0;transactions<4;transactions++){
                    if(transactions%2==0){
                        int buyStock=-prices[i]+after[transactions+1];
                        int dontBuyStock=0+after[transactions];
                        curr[transactions]=max(buyStock,dontBuyStock);
                    }
                    else{
                        int sellStock=prices[i]+after[transactions+1];
                        int dontSellStock=0+after[transactions];
                        curr[transactions]=max(sellStock,dontSellStock);
                    }
            }
            after=curr;
        }
        return after[0];
    }
    
};

class Solution2 {
    int recursion(vector<int> &prices,int m,int i,int buy){
        if(i>=m) return 0;
        int profit=0;
        if(buy)
        {
            int buyStock=-prices[i]+recursion(prices,m,i+1,0);
            int dontBuyStock=recursion(prices,m,i+1,1);
            profit=max(buyStock,dontBuyStock);
        }
        else
        {
            int sellStock=prices[i]+recursion(prices,m,i+2,1);
            int dontSellStock=0+recursion(prices,m,i+1,0);
            profit=max(sellStock,dontSellStock);
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        // return recursion(prices,m,0,1);
        vector<vector<int>> after(m+2,vector<int>(2,0));
        vector<vector<int>> curr(m+2,vector<int>(2,0));

        for(int i=m-1;i>-1;i--){
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                {
                    int buyStock=-prices[i]+after[i+1][0];
                    int dontBuyStock=after[i+1][1];
                    curr[i][buy]=max(buyStock,dontBuyStock);
                }
                else
                {
                    int sellStock=prices[i]+after[i+2][1];
                    int dontSellStock=0+after[i+1][0];
                    curr[i][buy]=max(sellStock,dontSellStock);
                }
            }
            after=curr;
        }
        return after[0][1];
    }
};

int main(){

return 0;
}