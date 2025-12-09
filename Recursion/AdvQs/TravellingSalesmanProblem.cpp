#include<iostream>
#include<vector>
#include<climits>
using namespace std;

using vi = vector<int> ; 
using vvi = vector<vi> ; 

class Solution {
    int recursion(int i,int mask,int n,int total,vvi &cost,vvi &dp){
        if(mask==total){
            if(i==0) return 0;
            return INT_MAX;
        }
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            if(mask>>j & 1) continue;
            int nextAns=recursion(j,mask|(1<<j),n,total,cost,dp);
            if(nextAns!=INT_MAX){
                ans=min(ans,cost[i][j]+nextAns);
            }
        }
        return dp[i][mask]=ans;
    }
  public:
    int tsp(vector<vector<int>> &cost) {
        // code here
        int n=cost.size();
        int total=(1<<n)-1;
        vvi dp(16,vi(total+1,-1));
        return recursion(0,0LL,n,total,cost,dp);
    }
};

int main(){

return 0;
}