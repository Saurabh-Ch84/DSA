#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(hashMap.count(num) && i-hashMap[num]<=k)
                return true;
            hashMap[num]=i;
        }
        return false;
    }
};

int main(){

return 0;
}