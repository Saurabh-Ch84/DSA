#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> result(n,false);

        int num=0;
        for(int i=0;i<n;i++){
            num=num<<1|nums[i];
            num=num%5;
            if(!num) result[i]=true;
        }

        return result;
    }
};

int main(){

return 0;
}