#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements1(vector<int>& nums) {
        // sorting approach
        sort(nums.begin(),nums.end());
        int n=nums.size(), expected=nums[0];
        vector<int> missing;
        for(int i=0;i<n;i++){
            int found=nums[i];
            while(found!=expected){
                missing.push_back(expected);
                expected++;
            }
            if(found==expected) expected++;
        }
        return missing;
    }
    vector<int> findMissingElements2(vector<int>& nums) {
        // bitset approach
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int range=maxi-mini+1, n=nums.size();
        vector<bool> found(range,0);
        
        for(int i=0;i<n;i++)
            found[nums[i]-mini]=1;
        vector<int> missing;
        for(int i=0;i<range;i++){
            if(!found[i]) missing.push_back(mini+i);
        }
        return missing;
    }
};

int main(){

return 0;
}