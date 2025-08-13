#include<iostream>
#include<vector>
using namespace std;

int recursion(vector<int> &arr,int i,int n,int currSum,vector<vector<int>> &dp){
    if(i>=n)
    {
        if(!currSum) return 1;
        return 0;
    }
    if(dp[i][currSum]!=-1) return dp[i][currSum];
    //notTake
    int notTake=recursion(arr,i+1,n,currSum,dp);
    //take
    int take=0;
    if(currSum>=arr[i]) take=recursion(arr,i+1,n,currSum-arr[i],dp);

    return dp[i][currSum]=take+notTake;
}

int main(){
    vector<int> arr={5,2,3,4,6,7};
    int sum=5;
    vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
    cout<<recursion(arr,0,arr.size(),sum,dp);
return 0;
}