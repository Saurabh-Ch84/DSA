#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prevCount(k,0), res(k,0);
        for(int i=0;i<n;i++){
            vector<long long> currCount(k,0);
            int currElementRem=nums[i]%k;
            currCount[currElementRem]++;
            for(int rem=0;rem<k;rem++){
                int rem_=((long long)rem*nums[i]%k)%k;
                currCount[rem_]+=prevCount[rem];
            }
            for(int rem=0;rem<k;rem++){
                res[rem]+=currCount[rem];
                prevCount[rem]=currCount[rem];
            }
        }
        return res;
    }
};

int main(){

return 0;
}