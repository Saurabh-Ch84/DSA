#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        
        for(int i=0;i<V-1;i++){
            for(vector<int> &vec:edges){
                int u=vec[0],v=vec[1],wt=vec[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                    dist[v]=dist[u]+wt;
            }
        }
        //negative cycles
        for(vector<int> &vec:edges){
            int u=vec[0],v=vec[1],wt=vec[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                return {-1};
        }
        return dist;
    }
    
};


int main(){

return 0;
}