#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
    using vll=vector<long long>;
    using vint=vector<int>;
    using vvll=vector<vll>;
    using vvvll=vector<vvll>;
    int gcd(int a,int b){
        while(b){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    long long recursion(int i,int gcdA,int gcdB,int n,vint &nums,vvvll &dp){
        if(i==n) return (gcdA==gcdB && gcdA);
        if(dp[i][gcdA][gcdB]!=-1) return dp[i][gcdA][gcdB];
        long long skip=recursion(i+1,gcdA,gcdB,n,nums,dp);
        long long take1=recursion(i+1,gcd(nums[i],gcdA),gcdB,n,nums,dp);
        long long take2=recursion(i+1,gcdA,gcd(nums[i],gcdB),n,nums,dp);
        return dp[i][gcdA][gcdB]=(skip+take1+take2)%mod;
    }
public:
    int subsequencePairCount(vector<int>& nums){
        int n=nums.size();
        vvvll dp(n,vvll(201,vll(201,-1)));
        return recursion(0,0,0,n,nums,dp);
    }
};

int main(){

return 0;
}