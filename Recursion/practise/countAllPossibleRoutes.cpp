#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    using vll=vector<long long>;
    using vvll=vector<vll>;
    int mod=1e9+7;
    long long recursion(int start,int finish,int n,int fuel,vint &locations,vvll &dp){
        if(!fuel) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        long long ways=0;
        for(int i=0;i<n;i++){
            int d=abs(locations[start]-locations[i]);
            if(i==start || d>fuel) continue;
            long long temp=(i==finish)+recursion(i,finish,n,fuel-d,locations,dp);
            ways=(ways+temp)%mod;
        }
        return dp[start][fuel]=ways;
    }
public:
    int countRoutes(vint &locations,int start,int finish,int fuel) {
        int n=locations.size();
        vvll dp(n+1,vll(fuel+1,-1));
        return recursion(start,finish,n,fuel,locations,dp)+(start==finish); // check if start==finish, then add 1 to the answer 
    }
};

class Solution2 {
    using vint=vector<int>;
    using vll=vector<long long>;
    using vvll=vector<vll>;
    int mod=1e9+7;
    long long recursion(int start,int finish,int n,int fuel,vint &locations,vvll &dp){
        if(fuel<0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        long long ways=0;
        if(start==finish) ways++;
        for(int i=0;i<n;i++){
            int d=abs(locations[start]-locations[i]);
            if(i==start || d>fuel) continue;
            long long temp=recursion(i,finish,n,fuel-d,locations,dp);
            ways=(ways+temp)%mod;
        }
        return dp[start][fuel]=ways;
    }
public:
    int countRoutes(vint &locations,int start,int finish,int fuel) {
        int n=locations.size();
        vvll dp(n+1,vll(fuel+1,-1));
        return recursion(start,finish,n,fuel,locations,dp);
    }
};

int main(){

return 0;
}