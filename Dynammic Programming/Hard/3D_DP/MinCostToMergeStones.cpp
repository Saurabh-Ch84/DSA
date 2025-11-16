#include<vector>
#include<iostream>
#include<climits>

using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;
using vvvi = vector<vvi> ;

const int INF = 1e9;

class Solution {
    int recursion(vector<int> &stones,int k){
        int n=stones.size();
        if(n==1) return 0;
        int ans=INT_MAX;
        for(int i=0;i+k<=n;i++){
            int cost=0;
            for(int j=i;j<i+k;j++)
                cost+=stones[j];

            vector<int> stones_;
            for(int j=0;j<i;j++)
                stones_.push_back(stones[j]);
            stones_.push_back(cost);
            for(int j=i+k;j<n;j++)
                stones_.push_back(stones[j]);

            int next=recursion(stones_,k);
            if(next!=INT_MAX)
                ans=min(ans,cost+next);
        }
        return ans;
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0) return -1;
        return recursion(stones,k);
    }
};


class Solution2 {
     // dp[i][j][m]

    int solve(int i, int j, int m, int k, vi &prefix, vvvi &dp) {
        if (i == j) return (m == 1 ? 0 : INF);
        if (dp[i][j][m] != -1) return dp[i][j][m];

        int res = INF;

        if (m == 1) {
            int temp = solve(i, j, k, k, prefix, dp);// build exactly K piles
            if (temp != INF)
                res = temp + (prefix[j+1] - prefix[i]); // pay sum to collapse K->1
        } else {
            for (int mid = i; mid < j; ++mid) {
                int left  = solve(i, mid, 1, k, prefix, dp); // left becomes 1 pile
                int right = solve(mid+1, j, m-1, k, prefix, dp);// right supplies m-1 piles
                if (left == INF || right == INF) 
                    continue;
                res = min(res, left + right);  // combine structure (no cost)
            }
        }
        return dp[i][j][m] = res;
    }

public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;

        // prefix sums
        vi prefix(n+1,0);
        prefix[0] = 0;
        for (int i = 0; i < n; ++i) 
            prefix[i+1] = prefix[i] + stones[i];

        vvvi dp(n+1,vvi(n+1,vi(k+1,-1)));
        return solve(0, n-1, 1, k, prefix, dp);
    }
};


int main(){

return 0;
}