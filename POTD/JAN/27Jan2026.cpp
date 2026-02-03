#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int> ;
using vvi = vector<vi> ;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vvpii = vector<vpii> ;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    
    bool DFS(int i,int j,int n,int m,int k,vi &di,vi &dj,vvc &mat,string &word){
        if(k==word.size()) return true;
        char orig=mat[i][j];
        mat[i][j]='#';
        for(int p=0;p<4;p++){
            int i_=i+di[p], j_=j+dj[p];
            if(!isValid(i_,j_,n,m) || mat[i_][j_]!=word[k])
                continue;
            if(DFS(i_,j_,n,m,k+1,di,dj,mat,word)){
                mat[i][j]=orig;
                return true;
            }
        }
        mat[i][j]=orig;
        return false;
    }
  public:
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n=mat.size(), m=mat[0].size(), len=word.size();
        vi di={-1,0,1,0}, dj={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0] && DFS(i,j,n,m,1,di,dj,mat,word))
                    return true;
            }
        }
        return false;
    }
};


class Solution {
    const int INF=1e9;
    void dijsktra(vi &dist,vvpii &adjList,int src=0){
        dist[src]=0;
        priority_queue<pii,vpii,greater<pii>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            pii entry=pq.top();pq.pop();
            int d=entry.first, u=entry.second;
            if(d>dist[u]) continue;
            for(pii p: adjList[u]){
                int d_=p.first+d, v=p.second;
                if(dist[v]>d_){
                    dist[v]=d_;
                    pq.push({d_,v});
                }
            }
        }
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vvpii adjList(n);
        for(vi &edge: edges){
            int u=edge[0], v=edge[1], w=edge[2];
            adjList[u].push_back({w,v});
            adjList[v].push_back({2*w,u});
        }

        vi dist(n,INF);
        dijsktra(dist,adjList);
        return (dist[n-1]==INF? -1: dist[n-1]);
    }
};

int main(){

return 0;
}