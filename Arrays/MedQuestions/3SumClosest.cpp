#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int minDist=INT_MAX;
        int closestSum=INT_MIN;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int dist=abs(sum-target);
                if(dist<minDist){
                    minDist=dist;
                    closestSum=sum;
                    if(closestSum==target) 
                        return closestSum;
                }
                if(sum<target) j++;
                else k--;
            }
        }
        return closestSum;
    }
};

int main(){

return 0;
}