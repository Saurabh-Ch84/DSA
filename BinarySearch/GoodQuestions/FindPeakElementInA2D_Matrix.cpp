#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;

// optimal Solution
class Solution {
    const int marker=-1e7;
    
    int maxRowIdx(int n,int mid,vvi &mat){
        int maxi=marker, idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>=maxi){
                maxi=mat[i][mid];
                idx=i;
            }
        }
        return idx;
    }
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        int low=0, high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int i=maxRowIdx(n,mid,mat);
            int val=(i==-1)? marker: mat[i][mid];
            int left=(mid)? mat[i][mid-1]:marker;
            int right=(mid+1<m)? mat[i][mid+1]:marker;
            if(val>=left && val>=right){
                return {i,mid};
            }
            else if(right>val){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
};

// Better hill climbing.
class Solution {
    const int marker=-1e7;
    
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    
    vi DFS(int i,int j,int n,int m,vi &di,vi &dj,vvi &mat){
        int orig=mat[i][j];
        bool flag=true;
        for(int k=0;k<4;k++){
            int i_=i+di[k], j_=j+dj[k];
            if(!isValid(i_,j_,n,m) || mat[i_][j_]==marker)
                continue;
            if(mat[i_][j_]>=mat[i][j]){
                if(mat[i_][j_]>mat[i][j]) flag=false;
                mat[i][j]=marker;
                vi nextAns=DFS(i_,j_,n,m,di,dj,mat);
                mat[i][j]=orig;
                if(nextAns[0]) return nextAns;
            }
        }
        if(flag) return {1,i,j};
        else return {0,-1,-1};
    }
    
  public:
  
    vi findPeakGrid(vvi & mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        vi di={-1,0,1,0}, dj={0,1,0,-1};
        vi ans=DFS(0,0,n,m,di,dj,mat);
        return {ans[1],ans[2]};
    }
};

int main(){

return 0;
}