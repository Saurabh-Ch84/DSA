#include<iostream>
#include<vector>
using namespace std;

// User function Template for C++
class Solution {
    class DSU{
        vector<int> parent;
            public:
        DSU(int n){
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find(int u){
            if(u==parent[u]) return u;
            return parent[u]=find(parent[u]);
        }
        bool unionIslands(int u,int v){
            int U=find(u);
            int V=find(v);
            if(U==V) return false;
            parent[U]=V;
            return true;
        }
    };
  public:
  
  bool isNotValid(int i,int j,int n,int m){
      if(i<0 || j<0 || i>=n || j>=m) return true;
      return false;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<bool>> grid(n,vector<bool>(m,false));
        DSU ds(m*n);
        vector<int> di={-1,0,1,0};
        vector<int> dj={0,1,0,-1};
        
        int countOfIslands=0;
        vector<int> output;
        
        for(vector<int> &coordinates:operators)
        {
            int i=coordinates[0],j=coordinates[1];
            if(!grid[i][j])
            {
                grid[i][j]=true;
                countOfIslands++;
                int nodeU=i*m+j;
                for(int k=0;k<4;k++)
                {
                    int newI=i+di[k],newJ=j+dj[k];
                    if(isNotValid(newI,newJ,n,m)) continue;
                    if(grid[newI][newJ])
                    {
                        int nodeV=newI*m+newJ;
                        if(ds.unionIslands(nodeU,nodeV)) 
                            countOfIslands--;
                    }
                }
            }
            output.push_back(countOfIslands);
        }
        return output;
    }
};


int main(){

return 0;
}