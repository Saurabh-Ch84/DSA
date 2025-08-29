#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Given a 2D array and starting coordinates, simulate water flow to adjacent cells based on terrain 
    height. Return a 2D array with time taken for water to reach each cell (unreachable points = -1).
*/

void print(vector<vector<int>> grid){
    for(vector<int> &row:grid){
        for(int &val:row)
            cout<<val<<" ";
        cout<<endl;
    }
    cout<<endl;
}

class Solution{
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
        public:
    vector<vector<int>> BFS(vector<vector<int>> &grid,int sX,int sY,int n,int m){
        vector<vector<int>> res(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        unordered_set<int> hashSet;
        
        q.push({sX,sY});
        hashSet.insert(sX*m+sY);
        res[sX][sY]=0;
        vector<int> di={-1,0,1,0},dj={0,1,0,-1};
        
        while(!q.empty()){
            int sz=q.size();
            for(int step=0;step<sz;step++)
            {
                pair<int,int> p=q.front();
                int i=p.first,j=p.second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int newI=i+di[k],newJ=j+dj[k];
                    if(isValid(newI,newJ,n,m) && grid[i][j]>=grid[newI][newJ] && hashSet.insert(newI*m+newJ).second)
                    {
                        q.push({newI,newJ});
                        res[newI][newJ]=res[i][j]+1;
                    }
                }
            }
        }
        return res;
    }
};


int main(){
    Solution s;

    int startX1 = 0, startY1 = 0;
    vector<vector<int>> heights1 = {
    {1, 2, 2},
    {3, 8, 2},
    {5, 3, 5}
    };

    vector<vector<int>> expected1 = {
        {0, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}
    };

    int startX2 = 1, startY2 = 1;
    vector<vector<int>> heights2 = {
    {1, 1, 1},
    {1, 2, 1},
    {1, 1, 1}
    };

    vector<vector<int>> expected2 = {
        {2, 1, 2},
        {1, 0, 1},
        {2, 1, 2}
    };

    print(heights1);
    print(s.BFS(heights1,startX1,startY1,heights1.size(),heights1[0].size()));

    print(heights2);
    print(s.BFS(heights2,startX2,startY2,heights2.size(),heights2[0].size()));
return 0;
}