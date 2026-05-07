#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using memo_t=unordered_map<int,unordered_map<int,int>>;
    class DSU{
            public:
        int n;
        vint parent, size;
        DSU(int n):n(n){
            parent.resize(n,-1);
            size.resize(n,1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }

        int find(int u){
            if(u==parent[u]) return u;
            return parent[u]=find(parent[u]);
        }

        void unionFind(int u,int v){
            int U=find(u), V=find(v);
            if(U==V) return ;
            n--;
            if(size[U]>=size[V]){
                parent[V]=U;
                size[U]+=size[V];
            }
            else{
                parent[U]=V;
                size[V]+=size[U];
            }
        }
    };
public:
    int minimumHammingDistance(vint &source,vint &target,vvint &allowedSwaps) {
        int n=source.size();
        DSU ds(n);

        for(vint &swaps: allowedSwaps){
            int u=swaps[0], v=swaps[1];
            ds.unionFind(u,v);
        }

        memo_t memo;
        for(int u=0;u<n;u++){
            int U=ds.find(u);
            memo[U][source[u]]++;
        }

        int count=0;
        for(int u=0;u<n;u++){
            int U=ds.parent[u];
            if(memo[U][target[u]]>0)
                memo[U][target[u]]--;
            else count++;
        }
        return count;
    }
};

class Solution{
    using pii=pair<int,int>;
    int BFS(int i,int j,int m,int n,int d){
        queue<pii> q;
        set<pii> visitedSet;
        q.push({i,j});
        visitedSet.insert({i,j});
        
        int moves=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pii entry=q.front(); q.pop();
                int u=entry.first, v=entry.second;
                if(u==d || v==d) return moves;
                //empty jug
                if(u>0 && !visitedSet.count({0,v})){
                    q.push({0,v});
                    visitedSet.insert({0,v});
                }
                if(v>0 && !visitedSet.count({u,0})){
                    q.push({u,0});
                    visitedSet.insert({u,0});
                }
                // fill jug
                if(u<m && !visitedSet.count({m,v})){
                    q.push({m,v});
                    visitedSet.insert({m,v});
                }
                if(v<n && !visitedSet.count({u,n})){
                    q.push({u,n});
                    visitedSet.insert({u,n});
                }
                // pour from i to j
                if(u>0 && v<n){
                    int x=min(u,n-v);
                    if(!visitedSet.count({u-x,v+x})){
                        q.push({u-x,v+x});
                        visitedSet.insert({u-x,v+x});
                    }
                }
                // pour from j to i
                if(v>0 && u<m){
                    int x=min(v,m-u);
                    if(!visitedSet.count({u+x,v-x})){
                        q.push({u+x,v-x});
                        visitedSet.insert({u+x,v-x});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
  public:
    int minSteps(int m, int n, int d) {
        // Code here
        return BFS(0,0,m,n,d);
    }
};



int main(){

return 0;
}