#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using pipii=pair<int,pair<int,int>>;
class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }

    int djikstra(int n,int m,vector<vector<int>> &grid){
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<int> di={1,0,0,-1},dj={0,1,-1,0};
        int maxTime=0;
        priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=true;

        while(!pq.empty()){
            pipii p=pq.top();
            pq.pop();
            int val=p.first;
            int i=p.second.first,j=p.second.second;
            maxTime=max(maxTime,val);
            if(i==n-1 && j==m-1) return maxTime;
            for(int k=0;k<4;k++){
                int i_=i+di[k],j_=j+dj[k];
                if(!isValid(i_,j_,n,m) || visited[i_][j_]) continue;
                pq.push({grid[i_][j_],{i_,j_}});
                visited[i_][j_]=true;
            }
        }
        return -1;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        return djikstra(n,m,grid);
    }
};

int main(){

return 0;
}