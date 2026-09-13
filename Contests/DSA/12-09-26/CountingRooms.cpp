#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    void DFS(int i,int j,int n,int m,vector<vector<char>> &buildingMap,vector<vector<bool>> &visited){
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int i_=i+dir[k][0], j_=j+dir[k][1];
            if(!isValid(i_,j_,n,m) || buildingMap[i_][j_]=='#' || visited[i_][j_]) continue;
            DFS(i_,j_,n,m,buildingMap,visited);
        }
    }
        public:
    int solve(int n,int m,vector<vector<char>> &buildingMap){
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        int rooms=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(buildingMap[i][j]=='.' && !visited[i][j]){
                    DFS(i,j,n,m,buildingMap,visited);
                    rooms++;
                }
            }
        }
        return rooms;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> buildingMap(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>buildingMap[i][j];
        }
    }
    Solution s;
    cout<<s.solve(n,m,buildingMap);
return 0;
}