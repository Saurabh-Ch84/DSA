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

int main(){

return 0;
}