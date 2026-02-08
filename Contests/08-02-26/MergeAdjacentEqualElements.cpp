#include<iostream>
#include<vector>
using namespace std;

using vll=vector<long long>;
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vll result;
        for(int i=0;i<n;i++){
            long long num=nums[i];
            while(!result.empty() && result.back()==num){
                result.pop_back();
                num=2*num;
            }
            result.push_back(num);
        }
        return result;
    }
};

int main(){

return 0;
}