#include<bits/stdc++.h>
using namespace std;

class Solution {
    int inf=1e6;
    int dp[3+1][501+1];
    int recursion(int i,int x,int n,vector<int> &areas,vector<int> &costs){
        if(i==n) return (x<=0? 0: inf);
        if(x<=0) return 0;
        if(dp[i][x]!=-1) return dp[i][x];
        int skip=recursion(i+1,x,n,areas,costs);
        int take=costs[i]+recursion(i,x-areas[i],n,areas,costs);
        return dp[i][x]=min(skip,take);
    }
  public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        vector<int> areas={s,m,l}, costs={cs,cm,cl};
        memset(dp,-1,sizeof(dp));
        return recursion(0,x,3,areas,costs);
    }
};

int main(){

return 0;
}