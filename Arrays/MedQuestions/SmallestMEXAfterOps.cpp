#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        unordered_map<int,int> hashMap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i] % value;
            if(val<0) val+=value;
            hashMap[val]++;
        }
        for(int i=0;i<n;i++){
            int i_= i % value;
            if(hashMap[i_]==0) return i;
            hashMap[i_]--;
        }
        return n;
    }
};

int main(){

return 0;
}