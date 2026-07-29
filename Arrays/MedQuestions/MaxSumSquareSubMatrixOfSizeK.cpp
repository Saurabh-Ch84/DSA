#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    class PrefixSum{
        int n,m;
        vvint prefix;
        void build(int n,int m,vvint &arr){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    prefix[i][j]=arr[i-1][j-1]+prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
                }
            }
        }
            public:
        PrefixSum(vvint &arr){
            n=arr.size(), m=arr[0].size();
            prefix.resize(n+1);
            for(int i=0;i<=n;i++)
                prefix[i].resize(m+1,0);
            build(n,m,arr);
        }
        int sumOfSubGrid(int r1,int c1,int r2,int c2){
            return prefix[r2+1][c2+1]-prefix[r2+1][c1]-prefix[r1][c2+1]+prefix[r1][c1];
        }
    };
  public:
    int maximumSum(vvint &mat,int k) {
        // code here
        PrefixSum ps(mat);
        int n=mat.size(), m=mat[0].size(), maxi=-1e9;
        for(int i=0;i<n;i++){
            int r1=i, r2=i+k-1;
            if(r2>=n) break;
            for(int j=0;j<m;j++){
                int c1=j, c2=j+k-1;
                if(c2>=m) break;
                maxi=max(maxi,ps.sumOfSubGrid(r1,c1,r2,c2));
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}