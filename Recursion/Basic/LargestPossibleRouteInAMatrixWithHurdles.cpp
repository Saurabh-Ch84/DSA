#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool isValid(int i,int j,int n,int m){
        return (i>=0 && j>=0 && j<m && i<n);
    }
    int dfs(int i,int j,int xd,int yd,int n,int m,vint &di,vint &dj,vvint &mat,vvint &visited){
        if(i==xd && j==yd) return 0;
        visited[i][j]=1;
        int ans=-1;
        for(int k=0;k<4;k++){
            int i_=i+di[k], j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || visited[i_][j_] || !mat[i_][j_])
                continue;
            int nextAns=dfs(i_,j_,xd,yd,n,m,di,dj,mat,visited);
            if(nextAns==-1) continue;
            ans=max(ans,nextAns+1);
        }
        visited[i][j]=0;
        return ans;
    }
  public:
    int longestPath(vvint &mat, int xs, int ys, int xd, int yd) {
        // code here
        if(!mat[xd][yd] || !mat[xs][ys]) return -1;
        int n=mat.size(), m=mat[0].size();
        vint di={-1,0,1,0}, dj={0,1,0,-1};
        vvint visited(n,vint(m,0));
        return dfs(xs,ys,xd,yd,n,m,di,dj,mat,visited);
    }
};

int main(){

return 0;
}