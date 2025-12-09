#include<iostream>
#include<vector>
using namespace std;

using pii = pair<int,int> ; 

class Solution {
    pii recursion(int i,int j,vector<int> &arr,bool turn, vector<vector<pii>> &dp){
        if(i>j) return {0,0};
        if(dp[i][j].first!=-1) return dp[i][j];
        // if(dp[i][j]!={-1,-1}) return dp[i][j]; //This is not correct.
        if(turn){
            pii leftTake=recursion(i+1,j,arr,false,dp);
            int leftScore=arr[i]+leftTake.first;
            pii rightTake=recursion(i,j-1,arr,false,dp);
            int rightScore=arr[j]+rightTake.first;
            if(leftScore>rightScore)
                return dp[i][j]={leftScore,leftTake.second};
            else
                return dp[i][j]={rightScore,rightTake.second};
        }
        else{
            pii leftTake=recursion(i+1,j,arr,true,dp);
            int leftScore=arr[i]+leftTake.second;
            pii rightTake=recursion(i,j-1,arr,true,dp);
            int rightScore=arr[j]+rightTake.second;
            if(leftScore>rightScore)
                return dp[i][j]={leftTake.first,leftScore};
            else
                return dp[i][j]={rightTake.first,rightScore};
        }
        return {-1,-1}; //dummy return.
    }
  public:
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<pii>> dp(n,vector<pii>(n,{-1,-1}));
        return recursion(0,n-1,arr,true,dp).first;
    }
};

int main(){

return 0;
}