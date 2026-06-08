#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> odd(n,0), even(n,0);
        for(int i=0;i<n;i++){
            if(nums[i] & 1) odd[i]=1;
            else even[i]=1;
        }
        for(int i=1;i<n;i++){
            odd[i]=odd[i-1]+odd[i];
            even[i]=even[i-1]+even[i];
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(nums[i] & 1) result.push_back(even[n-1]-even[i]);
            else result.push_back(odd[n-1]-odd[i]);
        }
        return result;
    }
};

int main(){

return 0;
}