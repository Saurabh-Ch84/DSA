#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops=0;
        for(int &num: nums){
            int rem=num % 3;
            if(rem) ops++;
        }
        return ops;
    }
};

int main(){

return 0;
}