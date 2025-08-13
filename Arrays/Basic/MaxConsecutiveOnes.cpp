#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,tempCount=0;
        for(int &val:nums)
        {
            if(val)
            {
                tempCount++;
                count=max(count,tempCount);
            }
            else tempCount=0;
        }
        return count;
    }
};

int main(){

return 0;
}