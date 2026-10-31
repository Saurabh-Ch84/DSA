#include<bits/stdc++.h>
using namespace std;

class Solution {
    using pii=pair<int,int>;
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool isValid(int i,int j,int n){
        return (i<n && j<n && i>=0 && j>=0);
    }
    int Dijkstra(int n,vvint &d,vvint &visited,vvint &matrix){
        priority_queue<vint,vvint> pq;
        pq.push({matrix[0][0],0,0});
        visited[0][0]=1;

        while(!pq.empty()){
            vint entry=pq.top(); pq.pop();
            int i=entry[1], j=entry[2], mini=entry[0];
            if(i==n-1 && j==n-1) return mini;
            for(int k=0;k<4;k++){
                int i_=i+d[k][0], j_=j+d[k][1];
                if(!isValid(i_,j_,n) || visited[i_][j_])
                    continue;
                pq.push({min(mini,matrix[i_][j_]),i_,j_});
                visited[i_][j_]=1;
            }
        }
        return -1;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vvint matrix(n,vint(n,-1));
        queue<pii> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    matrix[i][j]=0;
                }
            }
        }

        vvint d={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pii entry=q.front(); q.pop();
                int i=entry.first, j=entry.second;
                for(int k=0;k<4;k++){
                    int i_=i+d[k][0], j_=j+d[k][1];
                    if(!isValid(i_,j_,n) || matrix[i_][j_]!=-1)
                        continue;
                    matrix[i_][j_]=1+matrix[i][j];
                    q.push({i_,j_});
                }
            }
        }
        
        vvint visited(n,vint(n,0));
        return Dijkstra(n,d,visited,matrix);
    }
};

int main(){

return 0;
}