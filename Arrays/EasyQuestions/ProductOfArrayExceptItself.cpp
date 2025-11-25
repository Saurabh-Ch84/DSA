#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suffix(n,1);
        for(int i=n-2;i>=0;i--)
            suffix[i]=nums[i+1]*suffix[i+1];
        
        int prefix=1;
        for(int i=0;i<n;i++){
            suffix[i]=prefix*suffix[i];
            prefix=prefix*nums[i];
        }
        return suffix;
    }
};

int main(){

return 0;
}