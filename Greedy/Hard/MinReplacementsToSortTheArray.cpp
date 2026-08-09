#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long count=0;
        int n=nums.size(), prev=1e9+2;
        for(int i=n-1;i>=0;i--){
            int curr=nums[i];
            if(curr>prev){
                int parts=(curr/prev)+(curr%prev!=0);
                int ops=parts-1;
                count+=ops;
                prev=curr/parts;
            }
            else prev=curr;
        }
        return count;
    }
};

int main(){

return 0;
}