#include<iostream>
#include<vector>
using namespace std;

using pii=pair<int,int>;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<pii> range;
        int ptr=0, n=nums.size();
        bool flag=true;
        while(ptr<n){
            if(flag){
                range.push_back({ptr,ptr});
                ptr++;
                flag=false;
            }
            else{
                if(nums[ptr-1]==nums[ptr]-1){
                    range.back().second=ptr;
                    ptr++;
                }
                else flag=true;
            }
        }

        vector<string> result;
        for(const pii &r: range){
            int lb=r.first, ub=r.second;
            result.push_back(to_string(nums[lb]));
            if(lb!=ub) result.back()+="->"+to_string(nums[ub]);
        }
        return result;
    }
};

int main(){

return 0;
}