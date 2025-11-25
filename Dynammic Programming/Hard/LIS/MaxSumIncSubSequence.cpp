#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
    int recursion(int i,int n,vi &arr,int prevIndx,vvi &dp){
        if(i>=n) return 0;
        if(dp[i][prevIndx+1]!=-1) return dp[i][prevIndx+1];
        int notTake=recursion(i+1,n,arr,prevIndx,dp),take=0;
        if(prevIndx==-1 || arr[prevIndx]<arr[i]){
            take=arr[i]+recursion(i+1,n,arr,i,dp);
        }
        return dp[i][prevIndx+1]=max(notTake,take);
    }
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n=arr.size();
        vvi dp(n,vi(n+1,-1));
        return recursion(0,n,arr,-1,dp);
    }
};

int main(){

return 0;
}