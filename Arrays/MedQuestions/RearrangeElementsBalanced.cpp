#include<iostream>
#include<vector>
using namespace std;

//better version striver
class Solution1 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),pos=0,neg=1,ptr=0;
        vector<int> res(n);
        while(ptr<n){
            int num=nums[ptr];
            if(num>0){
                res[pos]=num;
                pos+=2;
            }
            else{
                res[neg]=num;
                neg+=2;
            }
            ptr++;
        }
        return res;
    }
};

// stiver's brute force
class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positiveNums,negativeNums;
        for(int &num:nums){
            if(num>0) positiveNums.push_back(num);
            else negativeNums.push_back(num);
        }
        int n=nums.size(),ptr=0;
        while(ptr<n/2){
            nums[ptr*2]=positiveNums[ptr];
            nums[ptr*2+1]=negativeNums[ptr];
            ptr++;
        }
        return nums;
    }
};


// my Approach brute force  
class Solution3 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positiveNums,negativeNums;
        for(int &num:nums){
            if(num>0) positiveNums.push_back(num);
            else negativeNums.push_back(num);
        }
        int n=nums.size(),left=0,right1=0,right2=0;
        while(left<n){
            if(left%2==0){
                nums[left]=positiveNums[right1];
                right1++;
            }
            else{
                nums[left]=negativeNums[right2];
                right2++;
            }
            left++;
        }
        return nums;
    }
};

int main(){

return 0;
}