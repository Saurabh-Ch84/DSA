#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // Brute-Force
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int tank,int n,int target,vvint &stations,vvint &dp){
        if(tank>=target) return 0;
        if(i>=n || tank<stations[i][0]) return 1e7;
        if(dp[i][tank]!=-1) return dp[i][tank];
        int skip=1e7, take=1e7;
        skip=recursion(i+1,tank,n,target,stations,dp);
        take=1+recursion(i+1,tank+stations[i][1],n,target,stations,dp);
        return dp[i][tank]=min(skip,take);
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vvint dp(n+1,vint(target+1,-1));
        int ans=recursion(0,startFuel,n,target,stations,dp);
        return (ans>=1e7? -1: ans);
    }
};

class Solution {
    // Optimal
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target,0});
        int n=stations.size(), currEnd=startFuel, count=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int position=stations[i][0], fuel=stations[i][1];
            if(currEnd>=target) break;
            while(currEnd<position && !pq.empty()){
                currEnd+=pq.top(); pq.pop();
                count++;
            }
            if(currEnd>=position) pq.push(fuel);
        }
        return (currEnd>=target? count: -1);
    }
};

int main(){

return 0;
}