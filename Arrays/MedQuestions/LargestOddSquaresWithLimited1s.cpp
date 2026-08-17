#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=std::vector<int>;
    using vvint=std::vector<vint>;
    class PrefixSum2D{
        vvint prefixSum;
            public:
        PrefixSum2D(vvint &mat){
            int n=mat.size(), m=mat[0].size();
            prefixSum.resize(n+1,vint(m+1,0));
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    prefixSum[i+1][j+1]=mat[i][j]+prefixSum[i+1][j]+prefixSum[i][j+1]-prefixSum[i][j];
                }
            }
        }
        
        int rangeSumQuery(int r1,int c1,int r2,int c2){
            int rangeSum=prefixSum[r2+1][c2+1]-prefixSum[r1][c2+1]-prefixSum[r2+1][c1]+prefixSum[r1][c1];
            return rangeSum;
        }
    };
    bool isValid(int r1,int c1,int r2,int c2,int n,int m){
        return (r1>=0 && r2<n && c1>=0 && c2<m);
    }
  public:
    vint largestSquare(vvint &mat, vvint &queries, int k) {
        // code here
        PrefixSum2D ps(mat);
        int q=queries.size(), n=mat.size(), m=mat[0].size();
        vint res(q,-1);
        for(int i=0;i<q;i++){
            int cR=queries[i][0], cC=queries[i][1];
            int r1=cR, c1=cC, r2=cR, c2=cC, side=-1;
            while(isValid(r1,c1,r2,c2,n,m) && ps.rangeSumQuery(r1,c1,r2,c2)<=k){
                side=(r2-r1+1);
                r2++, r1--;
                c2++, c1--;
            }
            res[i]=side;
        }
        return res;
    }
};

int main(){

return 0;
}