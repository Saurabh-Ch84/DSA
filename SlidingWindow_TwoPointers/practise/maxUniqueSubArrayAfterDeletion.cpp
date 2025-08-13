#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSum=INT_MIN,sum=0,maxi=INT_MIN;
        unordered_set<int> hashSet;
        for(int &num:nums){
            maxi=max(maxi,num);
            if(num>0 && hashSet.insert(num).second) sum+=num;
            maxSum=max(maxSum,sum);
        }
        return (maxSum==0)?maxi:maxSum;
    }
};

int main(){

return 0;
}