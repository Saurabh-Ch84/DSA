#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxi=nums.size();
        if(maxi<3) return maxi;
        for(int i=31;i>=0;i--){
            if(maxi & (1<<i))
                return (1<<(i+1));
        }
        return -1;
    }
};

int main(){

return 0;
}