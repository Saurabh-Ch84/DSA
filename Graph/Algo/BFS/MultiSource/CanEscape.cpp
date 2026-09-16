#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;
using vchar=vector<char>;
using vvchar=vector<vchar>;

class Solution{
    bool isValid(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    bool isBoundary(int i,int j,int n,int m){
        return (i==n-1 || i==0 || j==m-1 || j==0);
    }
    void multiSourceBFS(queue<pair<int,int>> &q,vint &di,vint &dj,int inf,int n,int m,vvint &fireTime,vvchar &grid){
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto entry=q.front(); q.pop();
                int i=entry.first, j=entry.second;
                for(int k=0;k<4;k++){
                    int i_=i+di[k], j_=j+dj[k];
                    if(!isValid(i_,j_,n,m) || grid[i_][j_]=='#' || fireTime[i_][j_]!=inf)
                        continue;
                    fireTime[i_][j_]=1+fireTime[i][j];
                    q.push({i_,j_});
                }
            }
        }
    }
        public:
    string canEscape(vvchar grid){
        int n=grid.size(), m=grid[0].size(), inf=1e9;
        queue<pair<int,int>> qFire, qHuman;
        vint di={-1,0,1,0}, dj={0,1,0,-1};
        vvint fireTime(n,vint(m,inf));
        vvint visited(n,vint(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='.' || grid[i][j]=='#')
                    continue;
                if(grid[i][j]=='F'){
                    qFire.push({i,j});
                    fireTime[i][j]=0;
                }
                else{
                    qHuman.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        if(qHuman.empty()) return "No Human";
        multiSourceBFS(qFire,di,dj,inf,n,m,fireTime,grid);
        int minutesPassed=1;
        while(!qHuman.empty()){
            int sz=qHuman.size();
            while(sz--){
                auto entry=qHuman.front(); qHuman.pop();
                int i=entry.first, j=entry.second;
                if(isBoundary(i,j,n,m)) return "YES";
                for(int k=0;k<4;k++){
                    int i_=i+di[k], j_=j+dj[k];
                    if(!isValid(i_,j_,n,m) || minutesPassed>=fireTime[i_][j_] || grid[i_][j_]=='#' || visited[i_][j_])
                        continue;
                    qHuman.push({i_,j_});
                    visited[i_][j_]=1;
                }
            }
            minutesPassed++;
        }
        return "NO";
    }
};

int main(){

return 0;
}