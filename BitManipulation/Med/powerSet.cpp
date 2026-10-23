#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int s=nums.size();
        vector<vector<int>> res;
        res.push_back({});
        for(int i=0;i<s;i++)
        {
            int size=res.size();
            for(int j=0;j<size;j++)
            {
                vector<int> temp1=res[j];
                temp1.push_back(nums[i]);
                res.push_back(temp1);
            }
        }
        return  res;
    }
};

int main(){

return 0;
}