#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool isValid(int i,int j,int m,int n){
        return (i<m && j<n && i>=0 && j>=0);
    }
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(), n=grid[0].size();
        priority_queue<vint,vvint> pq;
        pq.push({health-grid[0][0],0,0});
        vvint visited(m,vint(n,0)), d={{0,1},{0,-1},{1,0},{-1,0}};
        visited[0][0]=1;
        
        while(!pq.empty()){
            vint entry=pq.top(); pq.pop();
            int i=entry[1], j=entry[2], h=entry[0];
            if(h<=0) return false;
            if(i==m-1 && j==n-1) return h;
            for(int k=0;k<4;k++){
                int i_=i+d[k][0], j_=j+d[k][1];
                if(!isValid(i_,j_,m,n) || visited[i_][j_])
                    continue;
                pq.push({h-grid[i_][j_],i_,j_});
                visited[i_][j_]=1;
            }
        }
        return false;
    }
};

int main(){

return 0;
}