#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi=vector<int>;
using pbll=pair<bool,long long>;
using vpbll=vector<pbll>;
using vvpbll=vector<vpbll>;
using vvvpbll=vector<vvpbll>;

class Solution {
    const long long nInf=-1e16;
    long long recursion(int i,int j,int n,int m,int k,vi &nums1,vi &nums2,vvvpbll &dp){
        if(i>=n || j>=m || !k) return (k? nInf: 0);
        if(dp[i][j][k].first) return dp[i][j][k].second;
        long long take=1LL*nums1[i]*nums2[j]+recursion(i+1,j+1,n,m,k-1,nums1,nums2,dp);
        long long skip1=recursion(i+1,j,n,m,k,nums1,nums2,dp);
        long long skip2=recursion(i,j+1,n,m,k,nums1,nums2,dp);
        dp[i][j][k]={true,max({take,skip1,skip2})};
        return dp[i][j][k].second;
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(), m=nums2.size();
        vvvpbll dp(n+1,vvpbll(m+1,vpbll(k+1,{false,-1})));
        return recursion(0,0,n,m,k,nums1,nums2,dp);
    }
};

int main(){

return 0;
}