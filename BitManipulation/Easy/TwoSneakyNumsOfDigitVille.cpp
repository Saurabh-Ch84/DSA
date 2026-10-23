#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        int m=n-2,xorRes=0;

        for(int i=0;i<m;i++)
            xorRes=xorRes^i;
            
        for(int &i: nums)
            xorRes=xorRes^i;

        int trailingZeros=__builtin_ctz(xorRes);
        int mask=1<<trailingZeros;
        int setBucket=0,unsetBucket=0;
        
        for(int i=0;i<m;i++){
            if(mask & i)
                setBucket=setBucket^i;
            else 
                unsetBucket=unsetBucket^i;
        }

        for(int &i: nums){
            if(mask & i)
                setBucket=setBucket^i;
            else 
                unsetBucket=unsetBucket^i;
        }

        return {setBucket,unsetBucket};
    }
};

int main(){

return 0;
}