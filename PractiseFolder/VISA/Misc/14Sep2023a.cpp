#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>> finalImg(n,vector<int>(m,0));
        vector<int> di={-1,-1,-1,0,1,1,1,0,0};
        vector<int> dj={-1,0,1,1,1,0,-1,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0,sum=0;
                for(int k=0;k<9;k++){
                    int newI=i+di[k],newJ=j+dj[k];
                    if(isValid(newI,newJ,n,m)){
                        sum+=img[newI][newJ];
                        count++;
                    }
                }
                finalImg[i][j]=sum/count;
            }
        }
        return finalImg;
    }
};

int main(){

return 0;
}