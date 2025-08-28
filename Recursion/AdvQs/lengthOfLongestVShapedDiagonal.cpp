#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    
    int recursion(vector<vector<int>>& grid,int i,int j,int n,int m,
                  vector<vector<int>>& diag,bool canTurn,int k,int val)
    {
        int nI=i+diag[k][0],nJ=j+diag[k][1];
        if(!isValid(nI,nJ,n,m) || grid[nI][nJ]!=val) return 0;
        int len=0;
        int notTakeTurn=1+recursion(grid,nI,nJ,n,m,diag,canTurn,k,val==0?2:0);
        len=max(len,notTakeTurn);
        if(canTurn){
            int takeTurn=1+recursion(grid,nI,nJ,n,m,diag,false,(k+1)%4,val==0?2:0);
            len=max(len,takeTurn);
        }
        return len;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> diag={{-1,-1},{-1,1},{1,1},{1,-1}};
        int len=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++)
                        len=max(len,1+recursion(grid,i,j,n,m,diag,true,k,2));
                }
            }
        }
        return len;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
    cout<<s.lenOfVDiagonal(grid);
return 0;
}