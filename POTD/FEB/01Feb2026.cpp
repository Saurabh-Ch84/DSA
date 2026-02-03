#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size(), min1=nums[1], min2=nums[2];
        for(int i=3;i<n;i++){
            int num=nums[i];
            if(min1<=num && min2>num) min2=num;
            else if(min1>=num){
                min2=min(min2,min1);
                min1=num; 
            }
        }
        return nums[0]+min1+min2;
    }
};

int main(){

return 0;
}