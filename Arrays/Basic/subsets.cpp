#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> subset;
        subset.push_back({});
        for(int i=0;i<n;i++){
            int val=nums[i];
            int m=subset.size();
            for(int j=0;j<m;j++){
                vector<int> temp=subset[j];
                temp.push_back(val);
                subset.push_back(temp);
            }
        }
        return subset;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        for(int mask=0;mask<(1<<n);mask++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)) 
                    temp.push_back(nums[i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){

return 0;
}