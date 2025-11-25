#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int ptr=0,winSize=-1;
        while(ptr<n){
            if(nums[ptr]){
                if(winSize!=-1 && winSize<k)
                    return false;
                winSize=0;
            }
            else if(winSize!=-1) winSize++;
            ptr++;
        }
        return true;
    }
};

int main(){

return 0;
}