#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[(int)1e4*5+1];
    int customBinarySearch(vector<vector<int>>& events,int x,int low,int high){
        int ansIdx=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][0]>=x){
                ansIdx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ansIdx;
    }
    int recursion(int i,int n,vector<vector<int>>& events){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int skip=recursion(i+1,n,events);
        int k=customBinarySearch(events,events[i][1],i+1,n-1);
        int take=events[i][2]+recursion(k,n,events);
        return dp[i]=max(take,skip);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> events(n,vector<int>(3,-1));
        for(int i=0;i<n;i++){
            events[i][0]=startTime[i];
            events[i][1]=endTime[i];
            events[i][2]=profit[i];
        }
        sort(events.begin(),events.end());
        memset(dp,-1,sizeof(dp));
        return recursion(0,n,events);
    }
};

int main(){

return 0;
}