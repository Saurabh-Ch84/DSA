#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<climits>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool check(long totalSum,vvint &g){
        int m=g.size(), n=g[0].size();
        unordered_set<int> hashSet;
        long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                hashSet.insert(g[i][j]);
                sum+=g[i][j];
            }
            long rem=totalSum-sum;
            long diff=sum-rem;
            if(diff == 0) return true;
            if(diff<0 || diff >100000) continue;
            if(diff==g[0][0] || diff==g[i][n-1] || diff==g[i][0]) 
                return true;
            if(i>0 && n>1 && hashSet.count(diff))
                return true;
        }
        return false;
    }

    void rotateBy90(vvint &g){
        int m=g.size(), n=g[0].size();
        vvint gT(n,vint(m,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int i_=j, j_=m-1-i;
                gT[i_][j_]=g[i][j];
            }
        }
        g=gT;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        long totalSum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                totalSum+=grid[i][j];
        }
        vvint g=grid;
        for(int i=0;i<4;i++){
            if(check(totalSum,g))
                return true;
            rotateBy90(g);
        }
        return false;
    }
};

using vi = vector<int> ;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vvpii= vector<vpii> ;

class Solution2 {
    int dijsktra(int V,int src,int dest,vvpii &adj){
        priority_queue<pii,vpii,greater<pii>> pq;
        vi dist(V,INT_MAX),ways(V,0);
        pq.push({0,src});
        dist[src]=0,ways[src]=1;
        
        while(!pq.empty()){
            pii p=pq.top();pq.pop();
            int w=p.first,u=p.second;
            if(w>dist[u]) continue;
            for(pii &q: adj[u]){
                int w_=q.first,v=q.second;
                int d=w_+w;
                if(dist[v]>d){
                    dist[v]=d;
                    ways[v]=ways[u];
                    pq.push({dist[v],v});
                }
                else if(dist[v]==d) ways[v]+=ways[u];
            }
        }
        
        return ways[dest];
    }
    
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vvpii adj(V);
        for(vi &edge: edges){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({w,v});
            adj[v].push_back({w,u});
        }
        return dijsktra(V,0,V-1,adj);
    }
};

int main(){

return 0;
}