#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;
using vb = vector<bool> ;
using vvb = vector<vb> ;

class Solution2 {
    bool isValid(int i,int j,int n,int m){
        return (i<n && i>=0 && j<m && j>=0);
    }
    int dijkstra(int I,int J,int n,int m,vvi &mat){
        vvi dist(n,vi(m,INT_MAX));
        vi di={-1,0,1,0},dj={0,1,0,-1};
        priority_queue<vi,vvi,greater<vi>> pq;
        pq.push({0,I,J});
        dist[I][J]=0;
        
        while(!pq.empty()){
            vi entry=pq.top();pq.pop();
            int cost=entry[0];
            int i=entry[1],j=entry[2];
            if(i==n-1 && j==m-1)
                return cost;
            if(cost>dist[i][j])
                continue;
            for(int k=0;k<4;k++){
                int i_=i+di[k],j_=j+dj[k];
                if(!isValid(i_,j_,n,m)) 
                    continue;
                int diff=abs(mat[i][j]-mat[i_][j_]);
                int newCost=max(cost,diff);
                if(newCost<dist[i_][j_]){
                    dist[i_][j_]=newCost;
                    pq.push({newCost,i_,j_});
                }
            }
        }
        return -1;
    }
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        return dijkstra(0,0,n,m,mat);
    }
};


class Solution1 {
    bool isValid(int i,int j,int n,int m){
        return (i<n && i>=0 && j<m && j>=0);
    }
    int DFS(int i,int j,int n,int m,vi &di,vi &dj,vvi &mat,vvb &visited,int ans=0){
        if(i==n-1 && j==m-1){
            return ans;
        }
        visited[i][j]=true;
        int mini=INT_MAX;
        for(int k=0;k<4;k++){
            int i_=i+di[k],j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || visited[i_][j_])
                continue;
            int diff=abs(mat[i][j]-mat[i_][j_]);
            int next=DFS(i_,j_,n,m,di,dj,mat,visited,max(ans,diff));
            mini=min(mini,next);
        }
        visited[i][j]=false;
        return mini;
    }
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        vvb visited(n,vb(m,false));
        vi di={0,1,0,-1},dj={1,0,-1,0}; //r,d,l,u
        return DFS(0,0,n,m,di,dj,mat,visited);
    }
};


int main(){

return 0;
}