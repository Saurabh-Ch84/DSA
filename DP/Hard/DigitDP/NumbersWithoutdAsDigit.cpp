#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>; 
    int recursion(int i,int tight,int isStarted,string &num,int d,vvvint &dp){
        if(i==num.size()) return 1;
        if(dp[i][tight][isStarted]!=-1) return dp[i][tight][isStarted];
        int limit=9, ans=0;
        if(tight) limit=num[i]-'0'; // if we are still under the limit, we can only go up to the current digit
        for(int currD=0;currD<=limit;currD++){
            int ntight=(tight && (currD==limit)); // if we are still under the limit
            int nisStarted=(isStarted || currD!=0); // if we have started the number (to avoid leading zeros)
            if(nisStarted && currD==d) continue; // skip if the current digit is d and we have started the number
            ans+=recursion(i+1,ntight,nisStarted,num,d,dp); // move to the next digit
        }
        return dp[i][tight][isStarted]=ans;
    }
  public:
    int countWithout(int n, int d) {
        // code here
        // limit and isStarted are bools, 
        // limit indicates if we are still under the limit of the number, 
        // isStarted indicates if we have started forming the number (to avoid leading zeros)
        int digits=10+1, limit=2, isStarted=2; 
        string num=to_string(n);
        vvvint dp(digits,vvint(limit,vint(isStarted,-1)));
        return recursion(0,1,0,num,d,dp)-1; // subtract 1 to exclude the number 0
    }
};

int main(){

return 0;
}