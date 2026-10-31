#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

using vi = vector<int> ;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vvpii = vector<vpii> ;

class Solution {
    vi djisktra(int k,int n,vvpii &adjList){
        vi dist(n,INT_MAX);
        priority_queue<pii,vpii,greater<pii>> pq;
        dist[k-1]=0;
        pq.push({0,k-1});

        while(!pq.empty()){
            pii top=pq.top() ; pq.pop();
            int w=top.first,u=top.second;
            if(dist[u]<w) continue;
            for(auto &p: adjList[u]){
                int w_=p.first+w,v=p.second;
                if(w_<dist[v]){
                    dist[v]=w_;
                    pq.push({w_,v});
                }
            }
        }
        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vvpii adjList(n);
        for(vi &time: times){
            int u=time[0]-1,v=time[1]-1,w=time[2];
            adjList[u].push_back({w,v});
        }
        vi dist=djisktra(k,n,adjList);
        int ans=0;
        for(int &d: dist){
            if(d==INT_MAX) return -1;
            ans=max(ans,d);
        }
        return ans;
    }
};

int main(){

return 0;
}