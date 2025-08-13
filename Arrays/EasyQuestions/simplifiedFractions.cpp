#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int gcd(int x, int y) {
        while (y) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int denominator = 2; denominator <= n; denominator++) {
            for (int numerator = 1; numerator < denominator; numerator++) {
                if (gcd(numerator, denominator) == 1) {
                    ans.push_back(to_string(numerator) + "/" + to_string(denominator));
                }
            }
        }
        return ans;
    }
};

int main(){

return 0;
}