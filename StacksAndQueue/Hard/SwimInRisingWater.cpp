#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vi> ;
using vvb = vector<vb> ;
using pipii=pair<int,pair<int,int>>;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && i>=0 && j<m && j>=0);
    }

    bool DFS(int i,int j,int n,int m,vi &di,vi &dj,vvb &visited,vvi &grid,int mid){
        visited[i][j]=true;
        if(grid[i][j]>mid) return false;
        if(i==n-1 && j==m-1) return true;
        bool ans=false;
        for(int k=0;k<4;k++){
            int i_=i+di[k],j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || visited[i_][j_]) continue;
            bool nextAns=DFS(i_,j_,n,m,di,dj,visited,grid,mid);
            if(nextAns){
                ans=nextAns;
                break;
            }
        }
        return ans;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                low=min(low,grid[i][j]);
                high=max(high,grid[i][j]);
            }
        }
        int mini=-1;
        vi di={-1,0,1,0},dj={0,1,0,-1};
        while(low<=high){
            int mid=low+(high-low)/2;
            vvb visited(n,vb(m,false));
            bool response=DFS(0,0,n,m,di,dj,visited,grid,mid);
            if(response){
                mini=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return mini;
    }
};

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