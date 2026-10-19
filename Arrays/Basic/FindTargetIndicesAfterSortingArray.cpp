#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int leftCount=0, numCount=0;
        for(int &num: nums){
            if(num<target) leftCount++;
            else if(num==target) numCount++;
        }
        vector<int> res(numCount);
        int i=0;
        while(i<numCount){
            int index=leftCount+i;
            res[i]=index;
            i++;
        }
        return res;
    }
};

int main(){

return 0;
}