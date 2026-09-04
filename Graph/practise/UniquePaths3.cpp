#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int di[4]={-1,0,1,0}, dj[4]={0,1,0,-1};
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    int DFS(int i,int j,int k,int n,int m,int count,vvint &grid){
        if(grid[i][j]==2 && k==count) return 1;
        int val=grid[i][j];
        grid[i][j]=-1;
        int ans=0;
        for(int d=0;d<4;d++){
            int i_=i+di[d], j_=j+dj[d];
            if(!isValid(i_,j_,n,m) || grid[i_][j_]==-1)
                continue;
            ans=ans+DFS(i_,j_,k+1,n,m,count,grid);
        }
        grid[i][j]=val;
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), count=0;
        int sI=-1, sJ=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) continue;
                if(grid[i][j]==1){
                    sI=i, sJ=j;
                }
                count++;
            }
        }
        return DFS(sI,sJ,1,n,m,count,grid);
    }
};

int main(){

return 0;
}