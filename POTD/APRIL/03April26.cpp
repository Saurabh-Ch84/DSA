#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    vint diagView(vvint mat){
        // code here
        int n=mat.size();
        int m=2*n-1;
        vvint diag(m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int I=i+j;
                diag[I].push_back(mat[i][j]);
            }
        }
        
        vint result;
        for(int i=0;i<m;i++){
            result.insert(result.end(),diag[i].begin(),diag[i].end());
        }
        return result;
    }
};

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int countWalls(int left,int right,vint &arr){
        int lbIndx=lower_bound(arr.begin(),arr.end(),left)-arr.begin();
        int ubIndx=upper_bound(arr.begin(),arr.end(),right)-arr.begin();
        return ubIndx-lbIndx;
    }
    int recursion(int i,bool direction,int n,vvint &arr,vint &walls,vvint &range,vvint &dp){
        if(i==n) return 0;
        if(dp[i][direction]!=-1) return dp[i][direction];
        int left=range[i][0], right=range[i][1], position=arr[i][0];
        if(i && direction) left=max(left,range[i-1][1]+1);
        int shootLeft=countWalls(left,position,walls)+recursion(i+1,0,n,arr,walls,range,dp);
        int shootRight=countWalls(position,right,walls)+recursion(i+1,1,n,arr,walls,range,dp);
        return dp[i][direction]=max(shootLeft,shootRight);
    }
public:
    int maxWalls(vint &robots,vint &distance,vint &walls) {
        int n=robots.size();
        sort(walls.begin(),walls.end());

        vvint arr;
        for(int i=0;i<n;i++)
            arr.push_back({robots[i],distance[i]});
        
        sort(arr.begin(),arr.end());
        
        vvint range(n);
        for(int i=0;i<n;i++){
            int left=max( (i>0 ? arr[i-1][0]+1 : INT_MIN), arr[i][0]-arr[i][1] );
            int right=min( (i<n-1? arr[i+1][0]-1 : INT_MAX), arr[i][0]+arr[i][1] );
            range[i]={left,right};
        }
        vvint dp(n,vint(2,-1));
        return recursion(0,0,n,arr,walls,range,dp);
    }
};

int main(){

return 0;
}