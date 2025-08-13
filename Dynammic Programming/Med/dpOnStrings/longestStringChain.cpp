#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool compare(const string &a,const string &b){
        if(b.length()-1!=a.length()) return false;
        int successor_ptr=0,predecessor_ptr=0;
        while(successor_ptr<b.length())
        {
            if(b[successor_ptr]==a[predecessor_ptr]) predecessor_ptr++;
            successor_ptr++;
        }
        return (successor_ptr==b.length() && predecessor_ptr==a.length());
    }
    static bool comp(const string &a,const string &b){
        return a.length()<b.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int m=words.size();
        vector<int> dp(m, 1);
        int ans = 1;
        for (int i = 0; i < m; i++) {
            for (int prev = 0; prev < i; prev++)
            {
                if (compare(words[prev],words[i])  && dp[i] < 1 + dp[prev]) dp[i] = 1 + dp[prev];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


class Solution2 {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> lis(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && lis[i]<1+lis[prev])
                    lis[i]=1+lis[prev];
            }
        }
        vector<int> lds(n,1);
       for (int i = n - 1; i >= 0; i--) {
            for (int next = n - 1; next > i; next--) {
                if (nums[next] < nums[i] && lds[i] < 1 + lds[next])
                    lds[i] = 1 + lds[next];
            }
        }
        if(lis[n-1] == n || lds[0] == n) return 0;
        int ans=0;
        for(int i=0;i<n;i++)
             if(lis[i] > 1 && lds[i] > 1){
                ans = max(ans, lis[i] + lds[i] - 1);  
            }
        
        return ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> lis(n, {1,1});
        int maxLen = 1;
        for(int i = 0; i < n; i++) 
        {
            for(int prev = 0; prev < i; prev++) 
            {
                if(nums[prev] < nums[i]) 
                {
                    if(lis[i].first < lis[prev].first + 1) 
                    {
                        lis[i].first = lis[prev].first + 1;
                        lis[i].second = lis[prev].second;
                    } 
                    else if(lis[i].first == lis[prev].first + 1)
                        lis[i].second += lis[prev].second;
                }
            }
            maxLen = max(maxLen, lis[i].first);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) if(lis[i].first == maxLen) ans += lis[i].second;
        return ans;
    }
};


int main(){

return 0;
}