#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    int dp[(int)1e5*2+1];
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
        int take=1+recursion(k,n,events);
        return dp[i]=max(take,skip);
    }
public:
    int solve(int n,vector<vector<int>> &movieTimings){
        sort(movieTimings.begin(),movieTimings.end());
        memset(dp,-1,sizeof(dp));
        return recursion(0,n,movieTimings);
    }
};

class Solution2{
    struct Comp{
        bool operator()(const vector<int> &a,const vector<int> &b){
            int endA=a[1], endB=b[1];
            if(endA<endB) return 1;
            if(endA>endB) return 0;
            int startA=a[0], startB=b[0];
            if(endA==endB && startA<startB) return 1;
            return 0;
        }
    };
        public:
    int solve(int n,vector<vector<int>> &movieTimings){
        sort(movieTimings.begin(),movieTimings.end(),Comp());
        int count=0, lastEndTime=0;
        for(int i=0;i<n;i++){
            int startTime=movieTimings[i][0], endTime=movieTimings[i][1];
            if(startTime>=lastEndTime){
                count++;
                lastEndTime=endTime;
            }
        }
        return count;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> movieTimings(n,vector<int>(2,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>movieTimings[i][j];
        }
    }
    Solution2 s;
    cout<<s.solve(n,movieTimings);
return 0;
}