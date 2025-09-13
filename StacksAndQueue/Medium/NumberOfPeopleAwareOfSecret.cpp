#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
    int memoization(int day,int n,int delay,int forget,vector<int> &dp){
        if(day>=n) return 1;
        if(dp[day]!=-1) return dp[day];
        int ans=1;
        for(int day_=day+delay;day_<=min(day+forget,n);day_++){
            if(day_==day+forget){
                ans--;
                break;
            }
            ans=(ans+memoization(day_,n,delay,forget,dp))%MOD;
        }
        return dp[day]=ans;
    }
public:
    int peopleAwareOfSecret2(int n, int delay, int forget){
        vector<int> dp(n+1,-1);
        return memoization(1,n,delay,forget,dp);
    }
};

int main(){
    Solution s;
    cout<<s.peopleAwareOfSecret2(6,2,4)<<endl;
return 0;
}