#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
    Given an array of unique integers numbers, your task is to find the number of pairs of indices (i, j) 
    such that i ≤ j and the sum numbers[i] + numbers[j] is equal to some power of 2.

Note: The numbers 20  = 1, 21 = 2, 22 = 4, 23 = 8, etc. are considered to be powers of 2.

Example

For numbers = [1, -1, 2, 3], the output should be solution(numbers) = 5.
– There is one pair of indices where the sum of the elements is 20 = 1:(1, 2): numbers[1] + numbers[2] = -1 + 2 = 1
– There are two pairs of indices where the sum of the elements is 21 = 2: (0, 0) and (1, 3)
– There are two pairs of indices where the sum of the elements is 22 = 4: (0, 3) and (2, 2)
– In total, there are 1 + 2 + 2 = 5 pairs summing to powers of 2.

For numbers = [2], the output should be solution(numbers) = 1.
– The only pair of indices is (0, 0) and the sum is equal to 22 = 4. So, the answer is 1.

For numbers = [-2, -1, 0, 1, 2], the output should be solution(numbers) = 5.
– There are two pairs of indices where the sum of the elements is 20 = 1: (2, 3) and (1, 4)
– There are two pairs of indices where the sum of the elements is 21 = 2: (2, 4) and (3, 3)
– There is one pair of indices where the sum of the elements is 22 = 4: (4, 4)
– In total, there are 2 + 2 + 1 = 5 pairs summing to powers of 2. 

Guaranteed constraints:

1 ≤ numbers.length ≤ 105
-106 ≤ numbers[i] ≤ 106
This problem could be solved in a straightforward way by having two nested loops to choose each pair and check whether 
their sum is a power of two. But since the numbers array could be quite large, quadratic time complexity would be too 
much for this question. (To get more precise, it is O(n2 * log(MAX_NUMBER)) where MAX_NUMBER is the largest number seen 
in the array.)
*/

class Solution{
public:
    long long numOf2PowerSumPairs(vector<int> nums){
        long long count = 0; // Fix 1: Use long long to prevent overflow
        int n = nums.size();
        unordered_map<int, int> hashMap;
        
        // Fix 2: Increase range to cover max possible sum (2 * 10^6)
        // 2^21 is approx 2.09 million. 
        vector<int> powerOf2;
        for(int i = 0; i <= 21; i++) {
            powerOf2.push_back(1 << i); // 1 << i is bitwise shift for 2^i
        }
        
        for(int i = 0; i < n; i++){
            int num = nums[i];
            // 1. Add current number to map FIRST to handle the (i, i) case logic correctly
            // (The problem asks for i <= j, so we count pairs where current num is j)
            hashMap[num]++;
            // 2. Check all powers
            for(int &power : powerOf2){
                long long need = (long long)power - num;
                // Optimization: If 'need' is out of possible input range, skip query
                if (need < -1000000 || need > 1000000) continue;
                if(hashMap.count(need)){
                    count += hashMap[need];
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    cout<<s.numOf2PowerSumPairs({1,-1,2,3})<<endl;
    cout<<s.numOf2PowerSumPairs({-2,-1,0,1,2})<<endl;
    cout<<s.numOf2PowerSumPairs({2})<<endl;
    cout<<s.numOf2PowerSumPairs({9,8,3,1,5})<<endl;
return 0;
}
