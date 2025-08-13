#include<iostream>
#include<vector>
using namespace std;

class Solution {
    pair<int,int> check(vector<vector<int>> &mat,int row,int col,int mid,bool chooseRow){
        int maxEle=-1;
        if(chooseRow){
            int j=-1;
            for(int i=0;i<col;i++)
            {
                if(maxEle<mat[mid][i]){
                    maxEle=mat[mid][i];
                    j=i;
                }
            }
            int top=(mid>0)?mat[mid-1][j]:-1;
            int bottom=(mid<row-1)?mat[mid+1][j]:-1;
            if(maxEle>top && maxEle>bottom) return {0,j};
            else if(top>maxEle) return {-1,j};
            return {1,j};
        }
        else{
            int i=-1;
            for(int j=0;j<row;j++)
            {
                if(maxEle<mat[j][mid]){
                    maxEle=mat[j][mid];
                    i=j;
                }
            }
            int left=(mid>0)?mat[i][mid-1]:-1;
            int right=(mid<col-1)?mat[i][mid+1]:-1;
            if(maxEle>left && maxEle>right) return {0,i};
            else if(left>maxEle) return {-1,i};
            return {1,i};
        }
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=n-1;
        bool chooseRow=true;
        if(m>n){
            chooseRow=false;
            high=m-1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            auto res=check(mat,n,m,mid,chooseRow);
            int response=res.first,ans=res.second;
            if(response==0){
                if(chooseRow) return {mid,ans};
                return {ans,mid};
            }
            else if(response==-1) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};

int main(){

return 0;
}