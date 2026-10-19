#include<bits/stdc++.h>
using namespace std;

class Solution {
    void recursion(int i,int n,vector<int> &nums,vector<vector<int>> &res){
        if(i==n){
            res.push_back(nums);
            return ;
        }
        for(int j=i;j<n;j++){
            swap(nums[j],nums[i]);
            recursion(i+1,n,nums,res);
            swap(nums[j],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        recursion(0,n,nums,res);
        return res;
    }
};

int main(){

return 0;
}