#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vll=vector<long long>;
    using vvll=vector<vll>;
    long long recursion(int i,int n,vint &nums,string &s,bool wasPrevTaken,vvll &dp){
        if(i==n) return 0;
        if(dp[i][wasPrevTaken]!=-1) return dp[i][wasPrevTaken];
        long long takePrev=0, takeCurr=0;
        if(s[i]=='0') return dp[i][wasPrevTaken]=recursion(i+1,n,nums,s,false,dp);
        if(!wasPrevTaken) 
            takePrev=nums[i-1]+recursion(i+1,n,nums,s,false,dp);
        takeCurr=nums[i]+recursion(i+1,n,nums,s,true,dp);
        return dp[i][wasPrevTaken]=max(takePrev,takeCurr);
    }
public:
    long long maxTotal(vector<int>& nums,string s) {
        int n=s.size();
        vvll dp(n+1,vll(2,-1));
        return recursion(0,n,nums,s,true,dp);
    }
};

class Solution2 {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long total=0;
        int n=s.size(), i=0, j=0;
        while(i<n){
            while(!j && i<n && s[i]=='1'){
                total+=nums[i];
                i++;
            }
            if(s[i]=='0'){
                int mini=nums[i];
                j=i+1;
                total+=nums[i];
                while(j<n && s[j]=='1'){
                    total+=nums[j];
                    mini=min(mini,nums[j]);
                    j++;
                }
                total-=min(mini,nums[i]);
                i=j;
            }
        }
        return total;
    }
};

int main(){

return 0;
}