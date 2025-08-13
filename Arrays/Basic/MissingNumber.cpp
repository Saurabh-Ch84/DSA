#include<iostream>
#include<vector>
using namespace std;

//optimal
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0,actualSum=(n*(n+1))/2;
        for(int &num:nums) sum+=num;
        int missingNum=actualSum-sum;
        return missingNum;
    }
};

//most optimal striver's approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0,n=nums.size(),xor2=0;
        for(int i=0;i<n;i++){
            xor1=xor1^i;
            xor2=xor2^nums[i];
        }
        xor1=xor1^n;
        int missingNum=xor1^xor2;
        return missingNum;
    }
};

int main(){

return 0;
}