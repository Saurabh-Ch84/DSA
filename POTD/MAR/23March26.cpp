#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution1 {
    using pll=pair<long long,long long>;
    using vpll=vector<pll>;
    using vvpll=vector<vpll>;

    using vint=vector<int>;
    using vvint=vector<vint>;

    const int mod=1e9+7;
    pll recursion(vvint &grid,int i,int j,int m,int n,vvpll &dp){
        if(i==m-1 && j==n-1) return {grid[i][j],grid[i][j]};
        if(dp[i][j].first!=LLONG_MIN && dp[i][j].second!=LLONG_MAX) return dp[i][j];
        long long maxVal=LLONG_MIN, minVal=LLONG_MAX;
        if(i<m-1){
            pll next=recursion(grid,i+1,j,m,n,dp);
            maxVal=max({maxVal,next.first*grid[i][j],next.second*grid[i][j]});
            minVal=min({minVal,next.first*grid[i][j],next.second*grid[i][j]});
        }
        if(j<n-1){
            pll next=recursion(grid,i,j+1,m,n,dp);
            maxVal=max({maxVal,next.first*grid[i][j],next.second*grid[i][j]});
            minVal=min({minVal,next.first*grid[i][j],next.second*grid[i][j]});
        }
        return dp[i][j]={maxVal,minVal};
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vvpll dp(m+1,vpll(n+1,{LLONG_MIN,LLONG_MAX}));
        long long res=recursion(grid,0,0,m,n,dp).first;
        return (res<0 ? -1: res%mod);
    }
};

class Solution2 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    
    void DFS(int timer,int u,int &maxi,vint &visited,vint &dist,vvint &adjList){
        visited[u]=1;
        if(dist[u]!=-1){
            maxi=max(maxi,timer-dist[u]);
            return ;
        }
        dist[u]=timer;
        for(int &v: adjList[u]){
            DFS(timer+1,v,maxi,visited,dist,adjList);
        }
        dist[u]=-1;
    }
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        // code here
        vvint adjList(V);
        for(vint &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
        }
        int maxi=0;
        vint visited(V,0) ,dist(V,-1);
        for(int u=0;u<V;u++){
            if(!visited[u]){
                DFS(0,u,maxi,visited,dist,adjList);
            }
        }
        return (maxi? maxi: -1);
    }
};


int main(){

return 0;
}