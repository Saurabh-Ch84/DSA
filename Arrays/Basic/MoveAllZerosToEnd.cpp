#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//optimal
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPtr=-1,n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]==0){
                zeroPtr=i;
                break;
            }
        if(zeroPtr==-1) return ;
        for(int numPtr=zeroPtr+1;numPtr<n;numPtr++){
            if(nums[numPtr]){
                swap(nums[numPtr],nums[zeroPtr]);
                zeroPtr++;
            }
        }
    }
};

//brute complex
class Solution {
public:
    void moveZeroes(vector<int>& nums){ 
        int left=0,right=0,n=nums.size();
        while(left<n && right<n){
            while(left<n-1 && nums[left]!=0) left++;
            right=left+1;
            while(right<n && nums[right]==0) right++;
            if(right>=n) break;
            swap(nums[left],nums[right]);
            left++;
        }
    }
};

int main(){

return 0;
}