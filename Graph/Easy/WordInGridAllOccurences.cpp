#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>; 
    using vvchar=vector<vector<char>>;
    
    int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    bool DFS(int i,int j,int k,int d,int n,int m,int N,string &word,vvchar &mat){
        if(k==N-1) return (mat[i][j]==word[k]);
        if(mat[i][j]!=word[k]) return 0;
        int i_=i+dir[d][0], j_=j+dir[d][1];
        if(!isValid(i_,j_,n,m)) return 0;
        return DFS(i_,j_,k+1,d,n,m,N,word,mat);
    }
  public:
    vector<vector<int>> searchWord(vvchar &mat, string &word) {
        // Code here
        int n=mat.size(), m=mat[0].size(), N=word.size();
        vvint res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                    for(int d=0;d<8;d++){
                        if(DFS(i,j,0,d,n,m,N,word,mat)){
                            res.push_back({i,j});
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main(){

return 0;
}