#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution1 {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        unordered_set<int> prefixSumSet;
        for(int i=0;i<n;i++){
            int num=arr[i];
            int remNum=target-num;
            if(prefixSumSet.count(remNum)) return true;
            prefixSumSet.insert(num);
        }
        return false;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (indexMap.find(complement) != indexMap.end()) {
                return {indexMap[complement], i};  // ✅ correct order
            }

            indexMap[nums[i]] = i;
        }

        return {-1, -1};  // not found
    }
};


int main(){

return 0;
}