#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int cal(int digit){
        int dig=9,res=1;
        int lowBound=10-digit;
        while(dig>lowBound){
            res=res*dig;
            dig--;
        }
        return res;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        int a=1,b=0;
        for(int digit=1;digit<=n;digit++){
            b=9*cal(digit)+a;
            a=b;
        }
        return a;
    }
};

int main(){

return 0;
}