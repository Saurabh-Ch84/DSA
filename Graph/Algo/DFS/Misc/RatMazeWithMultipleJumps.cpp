#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool isValid(int i,int j,int n,int m){
        return (i<n && i>=0 && j<m && j>=0);
    }
    bool DFS(int i,int j,int n,int m,vvint &visited,vvint &arr,vvint &mat){
        if(!mat[i][j]) return false;
        if(i==n-1 && j==m-1) return mat[i][j];
        visited[i][j]=1;
        int k=1;
        while(k<=mat[i][j]){
            int j_=j+k;
            if(isValid(i,j_,n,m) && mat[i][j_] && !visited[i][j_]){
                arr[i][j_]=1;
                bool nextAns=DFS(i,j_,n,m,visited,arr,mat);
                if(nextAns) return nextAns;
                arr[i][j_]=0;
            }
            int i_=i+k;
            if(isValid(i_,j,n,m) && mat[i_][j] && !visited[i_][j]){
                arr[i_][j]=1;
                bool nextAns=DFS(i_,j,n,m,visited,arr,mat);
                if(nextAns) return nextAns;
                arr[i_][j]=0;
            }
            k++;
        }
        return false;
    }
  public:
    vvint shortestDist(vvint &mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        vvint visited(n,vint(m,0)), arr(n,vint(m,0));
        arr[0][0]=1;
        bool ans=DFS(0,0,n,m,visited,arr,mat);
        if(ans) return arr;
        return {{-1}};
    }
};

int main(){

return 0;
}
