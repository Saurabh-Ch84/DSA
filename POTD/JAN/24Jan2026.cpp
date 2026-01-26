#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
    int recursion(int n,int k){
        if(n==1) return 0;
        return (recursion(n-1,k)+k)%n;
    }
  public:
    int josephus(int n, int k) {
        // code here
        return recursion(n,k)+1;
    }
};

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(), ans=INT_MIN;
        int left=0, right=n-1;
        while(left<right){
            int pairSum=nums[left]+nums[right];
            ans=max(ans,pairSum);
            left++;
            right--;
        }
        return ans;
    }
};

int main(){

return 0;
}