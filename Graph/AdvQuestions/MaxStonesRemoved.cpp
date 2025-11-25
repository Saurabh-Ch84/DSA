#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Optimal 
class Solution {
    class DSU{
        vector<int> parent,size;
            public:
        DSU(int n){
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }  
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        void unionBySize(int u,int v){
            int U=find(u),V=find(v);
            if(U==V) return ;
            else if(size[U]<size[V]){
                parent[U]=V;
                size[V]+=size[U];
            }
            else{
                parent[V]=U;
                size[U]+=size[V];
            }
        }
        int numOfComps(){
            int comps=0,n=parent.size();
            for(int i=0;i<n;i++){
                if(parent[i]==i && size[i]>=2) comps++;
            }
            return comps;
        }
    };
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int numOfStones=stones.size();
        int n=0,m=0;
        // n=1e4+1,m=1e4+1;
        for(vector<int> &stone: stones){
            n=max(n,stone[0]);
            m=max(m,stone[1]);
        }
        n=n+1,m=m+1;
        DSU ds(n+m);
        
        for(vector<int> &stone: stones){
            int u=stone[0],v=n+stone[1];
            ds.unionBySize(u,v);
        }
        return numOfStones-ds.numOfComps();
    }
};

//not at all optimal
class Solution {
    int DFS(vector<vector<int>> &grid,int i,int j,int n,int m){
        if(grid[i][j]!=1) return 0;
        grid[i][j]=2;
        int stones=1;
        for(int row=0;row<n;row++)
            if(grid[row][j]==1) stones+=DFS(grid,row,j,n,m);
        for(int col=0;col<m;col++)
            if(grid[i][col]==1) stones+=DFS(grid,i,col,n,m);
        return stones;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=0,m=0;
        for(vector<int> &coordinates:stones){
            int x=coordinates[0],y=coordinates[1];
            n=max(y,n);
            m=max(x,m);
        }
        n=n+1,m=m+1;
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(vector<int> &coordinates:stones){
            int x=coordinates[0],y=coordinates[1];
            grid[y][x]=1;
        }
        
        int maxStonesRemoved=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int sizeOfComponent=DFS(grid,i,j,n,m);
                    maxStonesRemoved+=sizeOfComponent-1;
                }
            }
        }
        return maxStonesRemoved;
    }
};

//optimal DFS
class Solution2 {
    void DFS(vector<vector<int>> &adjList,vector<bool> &isVisited,int stone){
        isVisited[stone]=true;
        for(int &neighbourStone:adjList[stone])
            if(!isVisited[neighbourStone]) DFS(adjList,isVisited,neighbourStone);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int noOfStones=stones.size();
        unordered_map<int,vector<int>> rowMap;
        unordered_map<int,vector<int>> colMap;
        vector<vector<int>> adjList(noOfStones);
        vector<bool> visited(noOfStones,false);
        for(int stone=0;stone<noOfStones;stone++)
        {
            int i=stones[stone][0],j=stones[stone][1];
            for(int &neighbor:rowMap[i]){
                adjList[stone].push_back(neighbor);
                adjList[neighbor].push_back(stone);
            }
            for(int &neighbor:colMap[j]){
                adjList[stone].push_back(neighbor);
                adjList[neighbor].push_back(stone);
            }
            rowMap[i].push_back(stone);
            colMap[j].push_back(stone);
        }
        int components=0;
        for(int stone=0;stone<noOfStones;stone++){
            if(!visited[stone]){
                DFS(adjList,visited,stone);
                components++;
            }
        }
        int stonesRemoved=noOfStones-components;
        return stonesRemoved;
    }
};



int main(){

return 0;
}