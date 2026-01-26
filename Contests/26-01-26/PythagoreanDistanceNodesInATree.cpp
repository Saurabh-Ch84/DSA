#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;
class Solution {
    const int INF=1e9;
    void calculateDistance(vi &dist,vvi &edges,int node,vvi &adjList){
        queue<int> q;
        q.push(node);
        int distance=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front();q.pop();
                dist[u]=distance;
                for(int &v: adjList[u]){
                    if(dist[v]==INF)
                        q.push(v);
                }
            }
            distance++;
        }
    }
public:
    int specialNodes(int n,vvi & edges, int x, int y, int z) {
        vvi adjList(n);
        for(vi &edge: edges){
            int u=edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vi distX(n,INF), distY(n,INF), distZ(n,INF);
        calculateDistance(distX,edges,x,adjList);
        calculateDistance(distY,edges,y,adjList);
        calculateDistance(distZ,edges,z,adjList);

        int count=0;
        for(int i=0;i<n;i++){
            vi py={distX[i],distY[i],distZ[i]};
            sort(py.begin(),py.end());
            if(1LL*py[0]*py[0]+1LL*py[1]*py[1]==1LL*py[2]*py[2]) 
                count++;
        }
        return count;
    }
};

int main(){

return 0;
}