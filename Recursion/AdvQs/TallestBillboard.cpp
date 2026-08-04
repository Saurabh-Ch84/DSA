#include<bits/stdc++.h>
using namespace std;

// brute force solution 
class SolutionBrute {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    int recursion(int i,int n,int left,int right,vint &rods){
        if(i>=n){
            if(left==right) return left;
            return 0;
        }
        int skip=recursion(i+1,n,left,right,rods);
        int takeLeft=recursion(i+1,n,left+rods[i],right,rods);
        int takeRight=recursion(i+1,n,left,right+rods[i],rods);
        return max({skip,takeLeft,takeRight});
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        return recursion(0,n,0,0,rods);
    }
};

class SolutionOptimized {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int n,int d,int S,vint &rods,vvint &dp){
        if(i>=n){
            if(!d) return 0;
            return -1e9;
        }
        if(dp[i][S+d]!=-1) return dp[i][S+d];
        int skip=recursion(i+1,n,d,S,rods,dp);
        int takeLeft=rods[i]+recursion(i+1,n,d+rods[i],S,rods,dp);
        int takeRight=rods[i]+recursion(i+1,n,d-rods[i],S,rods,dp);
        return dp[i][S+d]=max({skip,takeLeft,takeRight});
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size(), S=accumulate(rods.begin(),rods.end(),0);
        vvint dp(n+1,vint(2*S+1,-1));
        return recursion(0,n,0,S,rods,dp)/2;
    }
};

int main(){

return 0;
}