#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1,ptr=n-1;
        vector<int> result;
        while(ptr>=0 || carry){
            int digit=(ptr>=0)? digits[ptr--]:0;
            int number=digit+carry;
            carry=number/10;
            digit=number % 10;
            result.push_back(digit);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main(){

return 0;
}