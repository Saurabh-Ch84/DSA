#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }

    int DFS(int i,int j,int n,int m,vi &di,vi &dj,vvi &LIP,vvi &matrix){
        if(LIP[i][j]!=-1) return LIP[i][j];
        int len=0;
        for(int k=0;k<4;k++){
            int i_=i+di[k],j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || matrix[i_][j_]<=matrix[i][j]) continue;
            int nextLen=DFS(i_,j_,n,m,di,dj,LIP,matrix);
            len=max(len,nextLen);
        }
        return LIP[i][j]=len+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vvi LIP(n,vi(m,-1));
        vi di={-1,0,1,0},dj={0,1,0,-1};
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(LIP[i][j]==-1){
                    int length=DFS(i,j,n,m,di,dj,LIP,matrix);
                    maxi=max(maxi,length);
                }
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}