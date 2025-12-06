#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using vi = vector<int> ;
using vvi = vector<vi> ;
class Solution {
    void recursion(vi &nums,int n,int idx,vi &temp,vvi &ans){
        ans.push_back(temp);
        for(int i=idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            recursion(nums,n,i+1,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vvi answer;
        vi temp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        recursion(nums,n,0,temp,answer);
        return answer;
    }
};

int main(){

return 0;
}