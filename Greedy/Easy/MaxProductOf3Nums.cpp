#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // Option 1: Three largest numbers
        int option1 = nums[n-1] * nums[n-2] * nums[n-3];
        // Option 2: Two smallest (negative) numbers and the largest number
        int option2 = nums[0] * nums[1] * nums[n-1];
        return max(option1, option2);
    }
};

class Solution2 {
    vector<int> find3MaxNums(vector<int>& nums) {
        int firstMax=-1e4, secondMax=-1e4, thirdMax=-1e4;
        for(int &num: nums){
            if(num>=firstMax){
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=num;
            }
            else if(num>=secondMax){
                thirdMax=secondMax;
                secondMax=num;
            }
            else if(num>thirdMax) thirdMax=num;
        }
        return {thirdMax,secondMax,firstMax};
    }
    vector<int> find2MinNums(vector<int>& nums) {
        int firstMin=1e4, secondMin=1e4;
        for(int &num: nums){
            if(num<=firstMin){
                secondMin=firstMin;
                firstMin=num;
            }
            else if(num<secondMin)
                secondMin=num;
        }
        return {firstMin,secondMin};
    }
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> _3Max=find3MaxNums(nums);
        vector<int> _2Min=find2MinNums(nums);
        int option1=_3Max[0]*_3Max[1]*_3Max[2];
        int option2=_2Min[0]*_2Min[1]*_3Max[2];
        return max(option1, option2);
    }
};

int main(){

return 0;
}