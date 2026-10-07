#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(), m=mat[0].size(), totalPerimeter=0;
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]) continue;
                int sidesExposed=0;
                for(int k=0;k<4;k++){
                    int ii=i+dir[k][0], jj=j+dir[k][1];
                    if(!isValid(ii,jj,n,m) || !mat[ii][jj]) 
                        sidesExposed++;
                }
                totalPerimeter+=sidesExposed;
            }
        }
        return totalPerimeter;
    }
};

int main(){

return 0;
}