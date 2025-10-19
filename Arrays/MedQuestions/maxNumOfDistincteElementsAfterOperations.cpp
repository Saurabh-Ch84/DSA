#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        
        int n=nums.size(),prev=INT_MIN,count=0;
        for(int i=0;i<n;i++){
            int minVal=nums[i]-k;
            if(prev<minVal){
                prev=minVal;
                count++;
            }
            else if(prev<nums[i]+k){
                prev+=1;
                count++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}