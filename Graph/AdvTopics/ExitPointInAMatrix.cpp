#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool isValid(int i,int j,int m,int n){
        return (i<m && j<n && i>=0 && j>=0);
    }
    vint DFS(int i,int j,int k,int m,int n,vvint &dir,vvint &mat){
        if(mat[i][j]){
            k=(k+1)%4;
            mat[i][j]=0;
        }
        int i_=i+dir[k][0], j_=j+dir[k][1];
        if(!isValid(i_,j_,m,n)) return {i,j};
        return DFS(i_,j_,k,m,n,dir,mat);
    }
  public:
    vint exitPoint(vvint &mat){
        // code here
        vvint dir={{0,1},{1,0},{0,-1},{-1,0}};
        int m=mat.size(), n=mat[0].size();
        return DFS(0,0,0,m,n,dir,mat);
    }
};

int main(){

return 0;
}