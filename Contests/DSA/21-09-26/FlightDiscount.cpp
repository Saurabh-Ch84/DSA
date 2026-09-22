#include<bits/stdc++.h>
using namespace std;

class Solution{
    long long inf=1e16;
    vector<vector<long long>> Dijkstra(int src,int dest,vector<vector<pair<int,int>>> &adj,int N){
        priority_queue<tuple<long long,int,bool>,vector<tuple<long long,int,bool>>,greater<tuple<long long,int,bool>>> pq;
        vector<vector<long long>> dist(N,vector<long long>(2,inf));
        pq.push({0,src,0});
        dist[src][0]=0;

        while(!pq.empty()){
            auto entry=pq.top(); pq.pop();
            long long w=get<0>(entry);
            int u=get<1>(entry), isDiscountUsed=get<2>(entry);
            if (w > dist[u][isDiscountUsed]) continue;
            for(auto &flight: adj[u]){
                int w_=flight.first, v=flight.second;
                long long d1=w+w_, d2=w+(w_)/2;
                if(dist[v][isDiscountUsed]>d1){
                    dist[v][isDiscountUsed]=d1;
                    pq.push({d1,v,isDiscountUsed});
                }
                if(!isDiscountUsed && dist[v][1]>d2){
                    dist[v][1]=d2;
                    pq.push({d2,v,1});
                }
            }
        }
        return dist;
    }
        public:
    long long solve(int N,int E,vector<tuple<int,int,int>> &flights){
        vector<vector<pair<int,int>>> adj(N);
        int src=0, dest=N-1;
        for(int i=0;i<E;i++){
            int u=get<0>(flights[i])-1, v=get<1>(flights[i])-1, w=get<2>(flights[i]);
            adj[u].push_back({w,v});
        }
        vector<vector<long long>> dist=Dijkstra(src,dest,adj,N);
        return dist[dest][1];
    }
};

int main(){
    int N,E;
    cin>>N>>E;
    vector<tuple<int,int,int>> flights(E);
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        flights[i] = {a, b, c};
    }
    Solution s;
    cout<<s.solve(N,E,flights);
return 0;
}