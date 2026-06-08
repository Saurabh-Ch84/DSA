#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int> ;
    void getNGE(vint &arr,vint &nge,int n){
        nge.resize(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>arr[st.top()])
                st.pop();
            if(!st.empty()) nge[i]=st.top();
            st.push(i);
        }
    }
    void getPGE(vint &arr,vint &pge,int n){
        pge.resize(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()])
                st.pop();
            if(!st.empty()) pge[i]=st.top();
            st.push(i);
        }
    }
    int findJumps(int i,vint &pge,vint &nge,int d,vint &dp){
        if(dp[i]!=-1) return dp[i];
        int l=max(pge[i]+1,i-d), r=min(nge[i]-1,i+d);
        int ans=1;
        for(int j=l;j<=r;j++){
            if(i==j) continue;
            int nAns=1+findJumps(j,pge,nge,d,dp);
            ans=max(ans,nAns);
        }
        return dp[i]=ans;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int maxi=0, n=arr.size();
        vint pge, nge;
        getPGE(arr,pge,n);
        getNGE(arr,nge,n);
        vint dp(n,-1);
        for(int i=0;i<n;i++)
            maxi=max(maxi,findJumps(i,pge,nge,d,dp));
        return maxi;
    }
};

int main(){

return 0;
}