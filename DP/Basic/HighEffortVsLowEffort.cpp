#include<bits/stdc++.h>
using namespace std;

class Solution {
    int recursion(int i,int n,vector<int> &h,vector<int> &l,
            bool wasPrevTaken,vector<vector<int>> &dp)
    {
        if(i==n) return 0;
        if(dp[i][wasPrevTaken]!=-1) return dp[i][wasPrevTaken];
        int chooseHighEffortTask=0, chooseLowEffortTask=0, skip=0;
        skip=recursion(i+1,n,h,l,0,dp);
        chooseLowEffortTask=l[i]+recursion(i+1,n,h,l,1,dp);
        if(!wasPrevTaken) chooseHighEffortTask=h[i]+recursion(i+1,n,h,l,1,dp);
        return dp[i][wasPrevTaken]=max({skip,chooseLowEffortTask,chooseHighEffortTask});
    }
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=h.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recursion(0,n,h,l,0,dp);
    }
};

int main(){

return 0;
}