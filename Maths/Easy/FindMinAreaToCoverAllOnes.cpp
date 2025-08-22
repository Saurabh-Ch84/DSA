#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int minRow=INT_MAX,maxRow=INT_MIN,maxCol=INT_MIN,minCol=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    minRow=min(minRow,i);
                    minCol=min(minCol,j);
                    maxRow=max(maxRow,i);
                    maxCol=max(maxCol,j);
                }
            }
        }
        if(minRow==INT_MAX) return 0;
        int length=maxRow-minRow+1;
        int breadth=maxCol-minCol+1;
        return length*breadth;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid={{0,1,0},{1,0,1},{0,0,0}};
    cout<<s.minimumArea(grid);
return 0;
}