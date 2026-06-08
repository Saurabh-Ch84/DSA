#include<iostream>
#include<vector>
using namespace std;

class Solution{
    int getCountOfDigit(int num,int digit){
        int count=0;
        while(num){
            int d=num%10;
            if(d==digit) count++;
            num=num/10;
        }
        return count;
    }
public:
    int countDigitOccurrences(vector<int>& nums, int digit){
        int count=0, n=nums.size();
        for(int i=0;i<n;i++)
            count+=getCountOfDigit(nums[i],digit);
        return count;
    }
};

int main(){

return 0;
}