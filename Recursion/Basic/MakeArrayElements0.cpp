#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//optimal solution
class Solution1 {
public:
    int countValidSelections(vector<int>& nums) {
        int rightSum=0,leftSum=0,count=0;
        for(int &num:nums)
            rightSum+=num;
        
        for(int &num:nums){
            if(num==0){
                if(leftSum>=rightSum && leftSum-rightSum<=1)
                    count++;
                if(rightSum>=leftSum && rightSum-leftSum<=1)
                    count++;
            }
            rightSum -= num;
            leftSum += num;
        }
        return count;
    }
};

//brute-force simulation
class Solution2 {
    bool recursion(int idx,int n,int sum,int dir,vector<int> &nums){
        if(sum==0) return true;
        if(idx>=n || idx<0) return false;
        if(nums[idx]==0) return recursion(idx+dir,n,sum,dir,nums);
        nums[idx]-=1;
        bool ans=recursion(idx-dir,n,sum-1,-dir,nums);
        nums[idx]+=1;
        return ans;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size(),sum=0;
        unordered_set<int> hashSet;
        for(int i=0;i<n;i++){
            if(nums[i]==0) hashSet.insert(i);
            sum+=nums[i];
        }
        
        if(sum==0) return 2*n;
        int count=0;
        for(int idx: hashSet){
            bool left=recursion(idx,n,sum,-1,nums);
            bool right=recursion(idx,n,sum,1,nums);
            if(left) count++;
            if(right) count++;
        }
        return count;
    }
};

int main(){

return 0;
}