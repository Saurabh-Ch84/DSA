#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<int>>& grid,int x,int y){
    int sum=grid[x][y];
    int right=300,bottom=300;
    if(x==grid.size()-1 && y==grid[0].size()-1)
        return grid[x][y];
    if(x+1<grid.size())    
        bottom=dfs(grid,x+1,y);
    if(y+1<grid[0].size())    
        right=dfs(grid,x,y+1);
    sum+=min(bottom,right);
    return sum;
}

int minPathSum1(vector<vector<int>>& grid){
    int ans=dfs(grid,0,0);
    return ans;
}

int minPathSum(vector<vector<int>> grids) {
    int m = grids.size();
    if (m == 0) return 0;
    int n = grids[0].size();
    if (n == 0) return 0;

    // vector<vector<int>> paths(grids);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i>1 && j>1)
                grids[i][j] += min(grids[i-1][j], grids[i][j-1]);
            else{
                if(i>1) grids[i][j] += grids[i-1][j];
                if(j>1) grids[i][j] += grids[i][j-1];
            }
        }
    }

    return grids[m-1][n-1];
}



int main(){
    vector<vector<int>> vec={{3,8,6,0,5,9,9,3,4,6,7},{9,2,5,5,4,9,1,4,56,7,8},{8,2,6,9,1,1,6,7,8,9,0},{0,1,4,7,9,0,1,2,3,5,6},{1,6,9,0,5,1,5,4,1,1,32},{2,1,7,9,0,6,11,3,4,8,9},{9,8,3,1,5,3,3,7,3,6,1},{6,2,9,0,5,0,0,8,7,3,1},{8,2,7,6,0,6,2,0,9,7,4},{1,2,3,4,5,6,7,8,9,0,1},{6,8,9,1,2,3,3,3,4,6,6},{1,2,3,4,5,6,7,8,9,0,1},{6,8,9,1,2,3,3,3,4,6,6},{1,2,3,4,5,6,7,8,9,0,1},{6,8,9,1,2,3,3,3,4,6,6},{1,2,3,4,5,6,7,8,9,0,1},{6,8,9,1,2,3,3,3,4,6,6},{1,2,3,4,5,6,7,8,9,0,1},{6,8,9,1,2,3,3,3,4,6,6}};
    cout<<"By Using DP:"<<minPathSum(vec)<<endl;
    cout<<"By Using Recursion:"<<minPathSum1(vec)<<endl;
return 0;
}