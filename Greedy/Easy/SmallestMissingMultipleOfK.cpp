#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int t=k, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                if(nums[i]<t) continue;
                else if(nums[i]==t) t+=k;
                else break;
            }
        }
        return t;
    }
};

int main(){

return 0;
}