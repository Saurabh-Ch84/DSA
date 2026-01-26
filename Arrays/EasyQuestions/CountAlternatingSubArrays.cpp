#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long count=0;
        int n=nums.size();

        int left=0;
        while(left<n){
            long long len=1;
            int right=left+1;
            while(right<n && nums[left]^nums[right]){
                left++;right++;len++;
            }
            count+=(len*(len+1))/2;
            left++;
        }

        return count;
    }
};

int main(){

return 0;
}