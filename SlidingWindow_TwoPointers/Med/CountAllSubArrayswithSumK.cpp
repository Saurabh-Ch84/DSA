#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> SumNumMap;
        SumNumMap[0]=1;
        int count=0,prefixSum=0;
        for(int &val:arr)
        {
            prefixSum+=val;
            int removeSum=prefixSum-k;
            count+=SumNumMap[removeSum];
            SumNumMap[prefixSum]+=1;
        }
        return count;
    }
};

int main(){

return 0;
}