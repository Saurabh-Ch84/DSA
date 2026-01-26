#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(nums.size()>1){
            if(is_sorted(nums.begin(),nums.end()))
                return count;
            int index=-1, val=INT_MAX, n=nums.size();
            for(int i=0;i<n-1;i++){
                int sum=nums[i]+nums[i+1];
                if(val>sum){
                    index=i;
                    val=sum;
                }
            }
            nums[index]=val;
            nums.erase(nums.begin()+index+1);
            count++;
        }
        return count;
    }
};

using vi = vector<int>;

class Solution {
    void calPGE(vi &v, vi &arr, int n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            v[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }

    void calPSE(vi &v, vi &arr, int n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            v[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }

    void calNGE(vi &v, vi &arr, int n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            v[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }

    void calNSE(vi &v, vi &arr, int n) {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            v[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }

public:
    long long subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        vi nge(n), pge(n), nse(n), pse(n);
        calPGE(pge, arr, n);
        calPSE(pse, arr, n);
        calNGE(nge, arr, n);
        calNSE(nse, arr, n);

        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            result += 1LL * arr[i] * leftMax * rightMax;

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            result -= 1LL * arr[i] * leftMin * rightMin;
        }
        return result;
    }
};


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int inversions = 0, count = 0;

        // Use a set to store {sum, index} for the greedy strategy
        set<pair<long long, int>> minSumSet;
        vector<int> prevIndex(n), nextIndex(n);
        
        // We use a separate vector to store current valid values 
        // because we update them lazily.
        // Actually, reusing 'nums' is fine if we are careful.
        // Let's use 'long long' for sums to prevent overflow.
        vector<long long> currentNums(n);

        // Initialize
        for (int i = 0; i < n; i++) {
            currentNums[i] = nums[i];
            prevIndex[i] = i - 1;
            nextIndex[i] = i + 1;

            if (i < n - 1) {
                long long pairSum = (long long)nums[i] + nums[i + 1];
                minSumSet.insert({pairSum, i});
                if (nums[i] > nums[i + 1]) inversions++;
            }
        }

        while (inversions > 0) {
            // 1. Pick the pair with the minimum sum
            auto it = minSumSet.begin();
            pair<long long, int> mini = *it;
            minSumSet.erase(it);

            long long sum = mini.first;
            int first = mini.second;       // Index of the left element of the pair
            int second = nextIndex[first]; // Index of the right element
            
            int leftFirst = prevIndex[first];  // Left neighbor
            int rightSecond = nextIndex[second]; // Right neighbor

            // 2. Remove Old Inversion Contributions
            // Check edge: First -> Second
            if (currentNums[first] > currentNums[second]) inversions--;

            // Check edge: Left -> First
            if (leftFirst != -1) {
                // Remove from Set
                long long oldLeftSum = currentNums[leftFirst] + currentNums[first];
                auto itL = minSumSet.find({oldLeftSum, leftFirst});
                if (itL != minSumSet.end()) minSumSet.erase(itL);
                // Remove inversion count
                if (currentNums[leftFirst] > currentNums[first]) inversions--;
            }

            // Check edge: Second -> Right
            if (rightSecond != n) {
                // Remove from Set
                long long oldRightSum = currentNums[second] + currentNums[rightSecond];
                auto itR = minSumSet.find({oldRightSum, second});
                if (itR != minSumSet.end()) minSumSet.erase(itR);
                // Remove inversion count
                if (currentNums[second] > currentNums[rightSecond]) inversions--;
            }

            // 3. Perform Merge
            currentNums[first] = sum; // Update value
            // Update pointers to skip 'second'
            nextIndex[first] = rightSecond;
            if (rightSecond != n) prevIndex[rightSecond] = first;
            
            // 4. Add New Inversion Contributions & Update Set
            
            // New Edge: Left -> Sum (First)
            if (leftFirst != -1) {
                minSumSet.insert({currentNums[leftFirst] + currentNums[first], leftFirst});
                if (currentNums[leftFirst] > currentNums[first]) inversions++;
            }
            // New Edge: Sum (First) -> Right
            if (rightSecond != n) {
                minSumSet.insert({currentNums[first] + currentNums[rightSecond], first});
                if (currentNums[first] > currentNums[rightSecond]) inversions++;
            }
            count++;
        }

        return count;
    }
};

int main(){

return 0;
}