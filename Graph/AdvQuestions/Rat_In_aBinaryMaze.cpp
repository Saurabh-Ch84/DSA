#include<iostream>
#include<queue>
using namespace std;

// User function Template for C++
// no need for priorityQueue just queue works.
class Solution1 {
    int BFS(vector<vector<int>> &a,
            int sx,int sy,int X,int Y,int n,int m){
        
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        dist[sx][sy]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{sx,sy}});
        
        vector<int> dx={-1,0,1,0};        
        vector<int> dy={0,1,0,-1};        
        while(!pq.empty()){
            int d=pq.top().first;
            int xU=pq.top().second.first;
            int yU=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int xV=xU+dx[i],yV=yU+dy[i];
                if(xV>=n || xV<0 || yV>=m || yV<0 || !a[xV][yV]) continue;
                if(dist[xV][yV]>d+1){
                    dist[xV][yV]=d+1;
                    pq.push({dist[xV][yV],{xV,yV}});
                }
            }
        }
        return (dist[X][Y]==1e8)?-1:dist[X][Y];
    }
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int x=0,y=0;
        if (!A[x][y] || !A[X][Y]) return -1;
        if(x==X && y==Y) return 0;
        return BFS(A,x,y,X,Y,N,M);
    }
};


// User function Template for C++
// optimal
class Solution2 {
    int BFS(vector<vector<int>> &a,
            int sx,int sy,int X,int Y,int n,int m){
        
        vector<vector<int>> dist(n,vector<int>(m,1e8));
        dist[sx][sy]=0;
        queue<pair<int,int>>q;        
        q.push({sx,sy});
        
        vector<int> dx={-1,0,1,0};        
        vector<int> dy={0,1,0,-1};        
        while(!q.empty()){
            int xU=q.front().first;
            int yU=q.front().second;
            int d=dist[xU][yU];
            q.pop();
            for(int i=0;i<4;i++){
                int xV=xU+dx[i],yV=yU+dy[i];
                if(xV>=n || xV<0 || yV>=m || yV<0 || !a[xV][yV]) continue;
                if(dist[xV][yV]>d+1){
                    dist[xV][yV]=d+1;
                    if (xV == X && yV == Y) return dist[xV][yV];
                    q.push({xV,yV});
                }
            }
        }
        return (dist[X][Y]==1e8)?-1:dist[X][Y];
    }
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int x=0,y=0;
        if (!A[x][y] || !A[X][Y]) return -1;
        if(x==X && y==Y) return 0;
        return BFS(A,x,y,X,Y,N,M);
    }
};

// User function Template for C++
// most optimal
class Solution3 {
    int BFS(vector<vector<int>> &A,
            int sx,int sy,int X,int Y,int n,int m){
    
        vector<vector<int>> a=A;
        queue<pair<int,int>>q;        
        q.push({sx,sy});
        
        vector<int> dx={-1,0,1,0};        
        vector<int> dy={0,1,0,-1};        
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int xU=q.front().first;
                int yU=q.front().second;
                q.pop();
                if(xU==X && yU==Y) return steps;
                for(int i=0;i<4;i++)
                {
                    int xV=xU+dx[i],yV=yU+dy[i];
                    if(xV>=n || xV<0 || yV>=m || yV<0 || !a[xV][yV]) continue;
                    a[xV][yV]=0;
                    q.push({xV,yV});
                }
            }
            steps++;
        }
        return -1;
    }
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int x=0,y=0;
        if (!A[x][y] || !A[X][Y]) return -1;
        if(x==X && y==Y) return 0;
        return BFS(A,x,y,X,Y,N,M);
    }
};

int main(){

return 0;
}