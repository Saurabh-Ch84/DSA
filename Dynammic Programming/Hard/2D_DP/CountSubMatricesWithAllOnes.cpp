#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> widthMatrix(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==1){
                    int right=(j < m-1)? widthMatrix[i][j+1]:0;
                    widthMatrix[i][j]=1+right;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) continue;
                int minWidth=widthMatrix[i][j];
                for(int k=i;k<n;k++){
                    if(widthMatrix[k][j]==0) break;
                    minWidth=min(minWidth,widthMatrix[k][j]);
                    count+=minWidth;
                }
            }
        }
        return count;
    }
};

int main(){

return 0;
}