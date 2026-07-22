#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi = vector<int> ;
using vs = vector<string> ;
using vvi = vector<vector<int>> ;
using vvvi = vector<vector<vector<int>>> ;

class Solution {
    int recursion(int i,int sz,int m,int n,vs &strs,vi &oneCount,vvvi &dp){
        if(i>=sz) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int notTake=recursion(i+1,sz,m,n,strs,oneCount,dp);
        int take=0,ones=oneCount[i],zeros=strs[i].length()-ones;
        if(zeros<=m && ones<=n)
            take=1+recursion(i+1,sz,m-zeros,n-ones,strs,oneCount,dp);
        return dp[i][m][n]=max(take,notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vi oneCount(sz,0);
        for(int i=0;i<sz;i++){
            int count1=count(strs[i].begin(),strs[i].end(),'1');
            oneCount[i]=count1;
        }
        vvvi dp(sz,vvi(m+1,vi(n+1,-1)));
        return recursion(0,sz,m,n,strs,oneCount,dp);
    }
};

int main(){

return 0;
}