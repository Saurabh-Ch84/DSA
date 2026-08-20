#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Time Complexity: O(n*k), Space Complexity: O(n)
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>> hashMap;
        for(int i=0;i<n-k+1;i++){
            int l=i, r=i+k-1;
            for(int j=l;j<=r;j++){
                // mark the index of the sliding window in the hashMap
                vector<int> &arr=hashMap[nums[j]];
                if(arr.empty() || arr.back()!=i) // to avoid duplicate indices 
                    hashMap[nums[j]].push_back(i);
                // cause the same number can may appear multiple times in the same sliding window
            }
        }
        int maxi=-1;
        for(auto &p: hashMap){
            if(p.second.size()==1)
                maxi=max(maxi,p.first);
        }
        return maxi;
    }
};

int main(){

return 0;
}