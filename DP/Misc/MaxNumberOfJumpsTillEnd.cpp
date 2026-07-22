#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using pinbo=pair<int,bool>;
    using vpinbo=vector<pinbo>;
    using vvint=vector<vint>;

    pinbo recursion(int i,int n,vint &nums,vvint &adjList,vpinbo &dp){
        if(i==n-1) return {0,true};
        if(dp[i].first!=-2) return dp[i];
        pinbo ans={-1,false};
        for(int &j: adjList[i]){
            pinbo nextAns=recursion(j,n,nums,adjList,dp);
            if(nextAns.second){
                ans.first=max(ans.first,1+nextAns.first);
                ans.second=true;
            }
        }
        return dp[i]=ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vvint adjList(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i]-nums[j])<=target){
                    adjList[i].push_back(j);
                }
            }
        }
        vpinbo dp(n,{-2,false});
        return recursion(0,n,nums,adjList,dp).first;
    }
};

int main(){

return 0;
}