#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

using vi=vector<int>;
using min_heap=priority_queue<int,vi,greater<int>>;
using max_heap=priority_queue<int>;

// brute-force
class Solution1 {
    const int inf=1e8;
    int recursion(int k,min_heap &minHeap,max_heap &maxHeap){
        if(minHeap.empty() || maxHeap.empty()) return inf;
        if(k*minHeap.top()-maxHeap.top()>=0) return 0;
        int takeMinHeap=inf, takeMaxHeap=inf;

        int mini=minHeap.top(); minHeap.pop();
        takeMinHeap=1+recursion(k,minHeap,maxHeap);
        minHeap.push(mini);

        int maxi=maxHeap.top(); maxHeap.pop();
        takeMaxHeap=1+recursion(k,minHeap,maxHeap);
        maxHeap.push(maxi);

        return min(takeMinHeap,takeMaxHeap);
    }
public:
    int minRemoval(vector<int>& nums, int k) {
        min_heap minHeap;
        max_heap maxHeap;
        for(int &num: nums){
            minHeap.push(num);
            maxHeap.push(num);
        }
        return recursion(k,minHeap,maxHeap);
    }
};

// Better-solution
using vi=vector<int>;
using vvi=vector<vi>;
class Solution2 {
    const int inf=1e8;
    int recursion(int i,int j,int n,int k,vi &nums,vvi &dp){
        if(i>j) return inf;
        if(dp[i][j]!=-1) return dp[i][j];
        if(1LL*k*nums[i]-1LL*nums[j]>=0) return 0;
        int takeMini=1+recursion(i+1,j,n,k,nums,dp);
        int takeMaxi=1+recursion(i,j-1,n,k,nums,dp);
        return dp[i][j]=min(takeMini,takeMaxi);
    }
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vvi dp(n,vi(n,-1));
        return recursion(0,n-1,n,k,nums,dp);
    }
};

class Solution3 {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0, right=0, mini=n;
        while(right<n){
            if(1LL*k*nums[left]-nums[right]<0)  
                left++;
            int curr=n-(right-left+1);
            mini=min(mini,curr);
            right++;
        }
        return mini;
    }
};

class Solution4 {

public:

    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int nA = a.size(), nB = b.size(), nC = c.size();
        int i = 0, j = 0, k = 0;

        int minDiff = INT_MAX, minSum = INT_MAX;
        vector<int> ans;
        while (i < nA && j < nB && k < nC) {
            int v1 = a[i], v2 = b[j], v3 = c[k];

            int currentMin = min({v1, v2, v3});
            int currentMax = max({v1, v2, v3});
            int diff = currentMax - currentMin;
            int sum = v1 + v2 + v3;

            if (diff < minDiff || (diff==minDiff && sum<minSum)) {
                minDiff = diff;
                minSum = sum;
                ans = {v1, v2, v3};
                sort(ans.rbegin(), ans.rend()); 
            }
            // GREEDY STEP: Always increment the pointer of the minimum value.
            if (v1 == currentMin) i++;
            else if (v2 == currentMin) j++;
            else k++;
        }

        return ans;

    }

};

int main(){

return 0;
}