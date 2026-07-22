#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int memo(vector<int>& arr,vector<vector<int>> &dp,int index,int target){
        if (index == 0) 
        {
            if (target == 0 && arr[0] == 0) return 2; // pick or not pick the zero
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake=memo(arr,dp,index-1,target);
        int take=0;
        if(target>=arr[index]) take=memo(arr,dp,index-1,target-arr[index]);
        return dp[index][target]=notTake+take;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
        return memo(arr,dp,arr.size()-1,target);
    }
};

int main(){

return 0;
}