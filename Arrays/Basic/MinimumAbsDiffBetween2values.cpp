#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size(), i=-1, j=-1, mini=1e9;
        for(int k=0;k<n;k++){
            if(!nums[k]) continue;
            if(nums[k]==1) i=k;
            else j=k;
            if(i!=-1 && j!=-1) mini=min(mini,abs(i-j));
        }
        return (mini==1e9? -1: mini);
    }
};

int main(){

return 0;
}