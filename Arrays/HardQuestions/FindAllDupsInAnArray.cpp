#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            int idx=num-1;
            if(nums[idx]<0) res.push_back(num);
            else nums[idx]*=-1;
        }
        return res;
    }
};

void print(vector<int> nums){
    for(int &num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<int> num1={9,8,3,1,5,3,2,7,2,6};
    print(s.findDuplicates(num1));
return 0;
}