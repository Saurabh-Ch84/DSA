#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;
using pii = pair<int,int> ;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && i>=0 && j<m && j>=0);
    }

    int BFS(queue<pii> &q,int fresh,int n,int m,vvi &grid){
        int time=0;
        vi di={-1,0,1,0},dj={0,1,0,-1};

        while(!q.empty()){
            int sz=q.size();
            bool rottenThisRound=false;
            while(sz--){
                pii entry=q.front();q.pop();
                int i=entry.first,j=entry.second;
                for(int k=0;k<4;k++){
                    int i_=i+di[k],j_=j+dj[k];
                    if(!isValid(i_,j_,n,m) || grid[i_][j_]!=1)
                        continue;
                    grid[i_][j_]=2;
                    fresh--;
                    rottenThisRound=true;
                    q.push({i_,j_});
                }
            }
            if(rottenThisRound) time++;
        }
        return (fresh)? -1: time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pii> q;

        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        return BFS(q,fresh,n,m,grid);
    }
};

int main(){

return 0;
}