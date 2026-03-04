#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size() , score1=0, score2=0;
        bool chance=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1) chance=!chance;
            if((i+1)%6==0) chance=!chance;
            if(chance) score1+=nums[i];
            else score2+=nums[i];
        }
        return score1-score2;
    }
};

int main(){

return 0;
}