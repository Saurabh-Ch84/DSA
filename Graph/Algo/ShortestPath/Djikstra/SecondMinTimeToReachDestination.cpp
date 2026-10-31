#include<bits/stdc++.h>
using namespace std;

class Solution {
    using piint=pair<int,int>;
    using vpiint=vector<piint>;
    using vint=vector<int>;
    using vvint=vector<vint>;

    int Dijkstra(int st,int dest,int n,vvint &adjList,int time,int change){
        priority_queue<piint,vpiint,greater<piint>> pq;
        pq.push({0,st});
        int inf=1e9;
        vint dist1(n,inf), dist2(n,inf);
        dist1[st]=0;

        while(!pq.empty()){
            piint entry=pq.top(); pq.pop();
            int t=entry.first, u=entry.second;
            if(dist2[u]<t) continue;
            if(u==dest && dist2[dest]!=inf) return dist2[dest];
            bool isRedLight=(t/change)%2;
            int waitTime=(isRedLight? change-(t%change):0);
            for(int &v: adjList[u]){
                int t_=t+time+waitTime;
                if(t_<dist1[v]){
                    dist2[v]=dist1[v];
                    dist1[v]=t_;
                    pq.push({t_,v});
                }
                else if(t_<dist2[v] && t_>dist1[v]){
                        dist2[v]=t_;
                        pq.push({t_,v});
                }
            }
        }
        return -1;
    }
public:
    int secondMinimum(int n,vvint &edges, int time, int change) {
        vvint adjList(n);
        for(vint &edge: edges){
            int u=edge[0]-1, v=edge[1]-1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return Dijkstra(0,n-1,n,adjList,time,change);
    }
};

int main(){

return 0;
}