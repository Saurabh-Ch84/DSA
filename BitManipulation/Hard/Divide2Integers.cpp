#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(dividend==divisor) return 1;

        bool sign=true;
        if(dividend<0 && divisor>0) sign=false;
        else if(divisor<0 && dividend>0) sign=false;

        long quotient=0,n=abs(long(dividend)),d=abs(long(divisor));
        while(d<=n)
        {
            long count=0;
            while(d<<(count+1) < n) count++;
            quotient+=1<<(count);
            n-=d<<count;
        }
        if(quotient>INT_MAX && sign) return INT_MAX;
        if(quotient<INT_MIN && !sign) return INT_MIN;
        return sign? quotient:-quotient;
    }
};

int main(){

return 0;
}