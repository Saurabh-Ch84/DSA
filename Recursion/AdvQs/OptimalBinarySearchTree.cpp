#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;
using vvvi = vector<vvi> ;

// Better
class Solution {
    int dp[102][102][102];
    int recursion(int i,int k,int level,vvi &arr){
        if(i>k) return 0;
        if(dp[i][k][level]!=-1) return dp[i][k][level];
        int mini=INT_MAX;
        for(int j=i;j<=k;j++){
            int cost=arr[j][1]*level;
            int leftCost=recursion(i,j-1,level+1,arr);
            int rightCost=recursion(j+1,k,level+1,arr);
            mini=min(mini,cost+leftCost+rightCost); 
        }
        return dp[i][k][level]=mini;
    }
  public:
    int minCost(vi &keys,vi &freq) {
        // code here
        int n=keys.size();
        memset(dp,-1,sizeof(dp));
        vvi arr;
        for(int i=0;i<n;i++)
            arr.push_back({keys[i],freq[i]});
        sort(arr.begin(),arr.end());
        return recursion(0,n-1,1,arr);
    }
};

//Optimal
class Solution {
    int dp[102][102];
    vi prefix;
    
    int getSum(int i,int k){
        return prefix[k+1]-prefix[i];
    }
    
    int recursion(int i,int k,vvi &arr){
        if(i>k) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int mini=INT_MAX;
        for(int j=i;j<=k;j++){
            int leftCost=recursion(i,j-1,arr);
            int rightCost=recursion(j+1,k,arr);
            mini=min(mini,leftCost+rightCost); 
        }
        return dp[i][k]=mini+getSum(i,k);
    }
  public:
    int minCost(vi &keys,vi &freq) {
        // code here
        int n=keys.size();
        vvi arr;
        for(int i=0;i<n;i++){
            arr.push_back({keys[i],freq[i]});
        }
        sort(arr.begin(),arr.end());
        prefix.assign(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+arr[i][1];
        }
        memset(dp,-1,sizeof(dp));
        
        return recursion(0,n-1,arr);
    }
};

int main(){

return 0;
}