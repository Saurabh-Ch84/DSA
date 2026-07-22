#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vector<int>> ;

class Solution {
    int recursion(int i,int n,vi &arr,vvi &dp,bool canBuy){
        if(i>=n) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int buyNow=0,buyLater=0,sellNow=0,sellLater=0;
        if(canBuy){
            buyNow=recursion(i+1,n,arr,dp,false)-arr[i];
            buyLater=recursion(i+1,n,arr,dp,true);
            dp[i][canBuy]=max(buyNow,buyLater);
        }
        else{
            sellNow=recursion(i+2,n,arr,dp,true)+arr[i];
            sellLater=recursion(i+1,n,arr,dp,false);
            dp[i][canBuy]=max(sellNow,sellLater);
        }
        return dp[i][canBuy];
    }
  public:
    int maxProfit(vector<int>& arr) {
        // code here
        int n=arr.size();
        vvi dp(n,vi(2,-1));
        return recursion(0,n,arr,dp,true);
    }
};

int main(){

return 0;
}