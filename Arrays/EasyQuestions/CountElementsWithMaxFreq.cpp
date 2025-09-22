#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> hashArr(100+1,0);
        int maxF=0;
        for(int &num:nums){
            hashArr[num]++;
            maxF=max(maxF,hashArr[num]);
        }
        int count=0;
        for(int &freq:hashArr)
            if(freq==maxF) count++;
        
        int ans=count*maxF;
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums={9,8,3,1,5,3,1,5};
    cout<<s.maxFrequencyElements(nums);
return 0;
}