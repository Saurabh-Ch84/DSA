#include<iostream>
#include<vector>
using namespace std;

class Solution{
    int recursiveFun(const vector<int> &a,int s,int e,int k)
    {
        if(s>=e) return 0;
        int minHealth=INT32_MAX;
        for(int i=s+1;i<=s+k && i<=e;i++)
        {
            int health=abs(a[s]-a[i])+recursiveFun(a,i,e,k);
            minHealth=min(minHealth,health);
        }
        return minHealth;
    }

    int memoizationFun(const vector<int> &a,int s,int e,int k,vector<int> &dp){
        if(s>=e) return 0;
        if(dp[s]!=-1) return dp[s];
        int minHealth=INT32_MAX;
        for(int i=s+1;i<=s+k && i<=e;i++)
        {
            int health=abs(a[s]-a[i])+memoizationFun(a,i,e,k,dp);
            minHealth=min(minHealth,health);
        }
        return dp[s]=minHealth;
    }

    int tabulationFun(const vector<int> &a,int k){
        int n=a.size();
        vector<int> dp(n,INT32_MAX);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                {
                    int health=dp[i-j]+abs(a[i]-a[i-j]);
                    dp[i]=min(dp[i],health);
                }
            }
        }
        return dp[n-1];
    }
        public:
    int findMinHealth(const vector<int> &arr,int k){
        int start=0,end=arr.size()-1;
        vector<int> memoDP(arr.size(),-1);
        // return recursiveFun(arr,start,end,k);
        // return memoizationFun(arr,start,end,k,memoDP);
        return tabulationFun(arr,k);
    }
};

int main(){
    Solution s;
    vector<int> v1 = {10, 20, 30, 10};
    vector<int> v2 = {30, 10, 60, 10, 60, 50};
    int k=3;
    cout<<"The Minimum Health required is: "<<s.findMinHealth(v2,k)<<endl;
return 0;
}