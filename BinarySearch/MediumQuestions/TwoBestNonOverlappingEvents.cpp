#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
    int upperBound(vvi &events,int i,int n){
        int i_=n, target=events[i][1];
        int low=i+1,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(events[mid][0]>target){
                i_=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return i_;
    }
    int recursion(int i,int k,int n,vvi &events,vvi &dp){
        if(i>=n || k==2) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int notTake=recursion(i+1,k,n,events,dp);
        int take=events[i][2];
        int i_=upperBound(events,i,n);
        take+=recursion(i_,k+1,n,events,dp);
        return dp[i][k]=max(take,notTake);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        vvi dp(n,vi(2,-1));
        return recursion(0,0,n,events,dp);
    }
};

int main(){

return 0;
}