#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int ub=pow(3,19);
        return ub%n==0;
    }
};

int main(){

return 0;
}