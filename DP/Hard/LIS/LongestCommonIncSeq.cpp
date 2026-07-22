#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

using vi = vector<int> ;

class Solution1 {
public:
    int LCIS(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<int> dp(m, 0);
        int result = 0;

        for (int i = 0; i < n; i++) {
            int current = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], current + 1);
                    result = max(result, dp[j]);
                }
                else if (a[i] > b[j]) {
                    current = max(current, dp[j]);
                }
            }
        }
        return result;
    }
};

class Solution2 {
    long long hash(int i,int j,int prev){
        return ((long long)i<<40)|
                ((long long)j<<20)|
                ((long long)prev+10000);
    }
    
    int recursion(int i,int n,int j,int m,vi &a,vi &b,
                int prev,unordered_map<long long,int> &dp)
    {
        if(i>=n || j>=m) return 0;
        long long key=hash(i,j,prev);
        if(dp.count(key)) return dp[key];
        int take=0,notTake=0;
        if(a[i]==b[j] && prev<a[i]){
            take=1+recursion(i+1,n,j+1,m,a,b,a[i],dp);
        }
        int notTakeA=recursion(i,n,j+1,m,a,b,prev,dp);
        int notTakeB=recursion(i+1,n,j,m,a,b,prev,dp);
        notTake=max(notTakeA,notTakeB);
        return dp[key]=max(take,notTake);
    }
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size(),m=b.size();
        unordered_map<long long,int> dp;
        return recursion(0,n,0,m,a,b,0,dp);
    }
};

class Solution3 {
    int recursion(int i,int n,int j,int m,vi &a,vi &b,
                int prev,unordered_map<string,int> &dp)
    {
        if(i>=n || j>=m) return 0;
        string key=to_string(i)+','+to_string(j)+','+to_string(prev);
        if(dp.count(key)) return dp[key];
        int take=0,notTake=0;
        if(a[i]==b[j] && prev<a[i]){
            take=1+recursion(i+1,n,j+1,m,a,b,a[i],dp);
        }
        int notTakeA=recursion(i,n,j+1,m,a,b,prev,dp);
        int notTakeB=recursion(i+1,n,j,m,a,b,prev,dp);
        notTake=max(notTakeA,notTakeB);
        return dp[key]=max(take,notTake);
    }
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size(),m=b.size(),maxi=1e4;
        unordered_map<string,int> dp;
        return recursion(0,n,0,m,a,b,0,dp);
    }
};

int main(){

return 0;
}