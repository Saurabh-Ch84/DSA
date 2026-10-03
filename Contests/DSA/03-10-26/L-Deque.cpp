#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<vector<long long>> dp;
    long long recursion(int i,int j,vector<int> &a){
        if(i>j) return 0;
        if(dp[i][j]!=LLONG_MAX) return dp[i][j];
        long long takeLeft=a[i]-recursion(i+1,j,a);
        long long takeRight=a[j]-recursion(i,j-1,a);
        return dp[i][j]=max(takeLeft,takeRight);
    }
        public:
    long long resultingValue(vector<int> &a){
        int n=a.size();
        dp.resize(n+1,vector<long long>(n+1,LLONG_MAX));
        return recursion(0,n-1,a);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    Solution s;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<s.resultingValue(a);
return 0;
}