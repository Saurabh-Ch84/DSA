#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    
    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }
    
    int recursion(int i,int j1,int j2,int n,int m,vint &dj,vvint &grid,vvvint &dp){
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=grid[i][j1];
        if(j1!=j2) ans+=grid[i][j2];
        if(i==n-1) return ans;
        int nextAns=0;
        for(int k1=0;k1<3;k1++){
            for(int k2=0;k2<3;k2++){
                int i_=i+1, j1_=j1+dj[k1], j2_=j2+dj[k2];
                if(!isValid(i_,j1_,n,m) || !isValid(i_,j2_,n,m))
                    continue;
                int tempAns=recursion(i_,j1_,j2_,n,m,dj,grid,dp);
                nextAns=max(nextAns,tempAns);
            }
        }
        return dp[i][j1][j2]=ans+nextAns;
    }
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(), m=grid[0].size();
        vint dj={-1,0,1};
        vvvint dp(n,vvint(m,vint(m,-1)));
        return recursion(0,0,m-1,n,m,dj,grid,dp);
    }
};

class Solution2 {
    void shiftLeft(vector<int> &row,int n){
        int temp=row[0];
        for(int i=1;i<n;i++){
            row[i-1]=row[i];
        }
        row[n-1]=temp;
    }
    void shiftRight(vector<int> &row,int n){
        int temp=row[n-1];
        for(int i=n-1;i>0;i--){
            row[i]=row[i-1];
        }
        row[0]=temp;
    }
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        k=k%n;
        vector<vector<int>> matrix=mat;
        for(int l=0;l<k;l++){
            for(int i=0;i<m;i++){
                if(i%2==0) shiftLeft(matrix[i],n);
                else shiftRight(matrix[i],n);
            }
        }
        return (matrix==mat);
    }
};

class Solution3{
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        k=k%n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int orig=mat[i][j], shifted=-1;
                if(i%2==1) shifted=mat[i][(j+k)%n];
                else shifted=mat[i][(j-k+n)%n];
                if(orig!=shifted) return false;
            }
        }
        return true;
    }
};

int main(){

return 0;
}