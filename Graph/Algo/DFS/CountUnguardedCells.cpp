#include<iostream>
#include<vector>
using namespace std;

using vvi = vector<vector<int>> ;
using vvc = vector<vector<char>> ;
using vc = vector<char> ;
using vi = vector<int> ;
using pii = pair<int,int> ;

class Solution {
    bool isValid(int m,int n,int i,int j){
        return (i<m && i>=0 && j<n && j>=0);
    }

    void DFS(int i,int j,int m,int n,vvc &grid,int di,int dj){
        int i_=i+di,j_=j+dj;
        if(!isValid(m,n,i_,j_) || grid[i_][j_]=='G' || grid[i_][j_]=='W')
            return ;
        grid[i_][j_]='O';
        DFS(i_,j_,m,n,grid,di,dj);
    }

public:
    int countUnguarded(int m, int n, vvi &guards, vvi &walls) {
        vvc grid(m,vc(n,'U'));

        for(vi &guard: guards){
            int i=guard[0],j=guard[1];
            grid[i][j]='G';
        }

        for(vi &wall: walls){
            int i=wall[0],j=wall[1];
            grid[i][j]='W';
        }

        vi di={-1,0,1,0},dj={0,1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='G'){
                    for(int k=0;k<4;k++){
                        DFS(i,j,m,n,grid,di[k],dj[k]);
                    }
                }
            }
        }


        int unguardedCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='U')
                    unguardedCount++;
            }
        }
        return unguardedCount;
    }
};

int main(){

return 0;
}