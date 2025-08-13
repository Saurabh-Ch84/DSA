#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    int findAnswer0(vector<int> &n, int s, int e,int &a,int c=0) {
        if (s == e) return c;
        for(int i=s+1;i<=s+2;i++){
            if(i<=e){
                int ans=findAnswer0(n,i,e,a,c+abs(n[i]-n[s]));
                if(a>ans) a=ans;
            }
        }
        return a;
    }
    int findAnswer1(vector<int> &n, int s, int e) {
        if (s == e) return 0;
        if (s > e) return INT_MAX; // Not needed in practice, but safe
        int jump1 = abs(n[s] - n[s+1]) + findAnswer1(n, s+1, e);
        int jump2 = (s+2 <= e) ? abs(n[s] - n[s+2]) + findAnswer1(n, s+2, e) : INT_MAX;
        return min(jump1, jump2);
    }

    int findAnswer2(vector<int> &n,int e){
        if(e==0) return 0;
        if(e<0) return INT_MAX;
        int jump1=abs(n[e]-n[e-1])+findAnswer2(n,e-1);
        int jump2=(e>1)? abs(n[e]-n[e-2])+findAnswer2(n,e-2):INT_MAX;
        return min(jump1,jump2);
    }

    int findAnswer3(vector<int> &n,vector<int> &dp,int e){
        if(e==0) return 0;
        if(e<0) return INT_MAX;
        if(dp[e]!=INT_MAX) return dp[e];
        int jump1=abs(n[e]-n[e-1])+findAnswer3(n,dp,e-1);
        int jump2=(e>1)?abs(n[e]-n[e-2])+findAnswer3(n,dp,e-2):INT_MAX;
        return dp[e]=min(jump1,jump2);
    }

    int findAnswer4(vector<int> &n,vector<int> &dp,int size){
        dp[0]=0;
        for(int i=1;i<size;i++){
            int jump1=dp[i-1]+abs(n[i]-n[i-1]);
            int jump2=INT_MAX;
            if(i>1) jump2=dp[i-2]+abs(n[i]-n[i-2]);
            dp[i]=min(jump1,jump2);
        }
        return dp[size-1];
    }

    int findAnswer5(vector<int> &n,int size){
        int prev=0,prev2=0;
        for(int i=1;i<size;i++){
            int jump1=prev+abs(n[i]-n[i-1]);
            int jump2=INT_MAX;
            if(i>1) jump2=prev2+abs(n[i]-n[i-2]);
            int curr=min(jump1,jump2);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
public:
    int findMinHealth(vector<int> &nums) {
        if (nums.empty()) return 0;
        int start = 0, end = nums.size() - 1;
        // return findAnswer1(nums, start, end);
        // return findAnswer2(nums,end);
        // vector<int> dp1(nums.size(),INT_MAX);
        // vector<int> dp2(nums.size(),0);
        // return findAnswer4(nums,dp2,end+1);
        // return findAnswer5(nums,end+1);
        int ans=INT_MAX;
        return findAnswer0(nums,start,end,ans);
    }
};

int main() {
    Solution s;
    vector<int> v1 = {10, 20, 30, 10};
    vector<int> v2 = {30, 10, 60, 10, 60, 50};
    cout << "The Minimum health is: " << s.findMinHealth(v2) << endl;
    return 0;
}
