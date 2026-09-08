#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> hashMap={{0,-1}};
        int sum=0, n=nums.size(), maxi=0;
        for(int i=0;i<n;i++){
            sum=sum+(nums[i]? 1:-1);
            int remSum=sum-0;
            if(hashMap.count(remSum)){
                int sz=i-hashMap[remSum];
                maxi=max(maxi,sz);
            }
            if(!hashMap.count(sum))
                hashMap[sum]=i;
        }
        return maxi;
    }
};

int main(){

return 0;
}