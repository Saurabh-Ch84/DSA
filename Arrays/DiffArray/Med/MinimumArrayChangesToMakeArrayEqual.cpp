#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size(), mini=2*n;
        for(int diff=0;diff<=k;diff++){
            int moves=0;
            for(int i=0;i<n/2;i++){
                int a=nums[i], b=nums[n-i-1];
                int d=abs(a-b);
                if(d==diff) continue;
                int maxVal=max({a,b,k-min(a,b)});
                if(maxVal>=diff) moves+=1;
                else moves+=2;
            }
            mini=min(mini,moves);
        }
        return mini;
    }
};

class Solution2 {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diffArr(k + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - i - 1];
            int d = abs(a - b);

            // base cost of 2 for every possible target diff in [0, k]
            diffArr[0] += 2, diffArr[k + 1] -= 2;

            // cost drops to 1 for target diff in [0, maxVal]
            // (achievable by changing just one of a, b)
            int maxVal = max({a, b, k - a, k - b});
            diffArr[0] += -1, diffArr[maxVal + 1] -= -1;

            // cost drops to 0 exactly at the pair's current diff
            diffArr[d] += -1, diffArr[d + 1] -= -1;
        }

        int mini = INT_MAX, currMin = 0;
        for (int i = 0; i <= k; i++) {
            currMin += diffArr[i];
            mini = min(mini, currMin);
        }
        return mini;
    }
};

int main(){

return 0;
}