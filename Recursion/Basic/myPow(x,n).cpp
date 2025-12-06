#include<iostream>
using namespace std;

class Solution {
    double helper(double x,long long n){
        if(x==1.0) return 1.0;
        if(n<0) return helper(1/x,-n);
        double result=1.0;
        while(n){
            if(n%2) result=result*x;
            x=x*x;
            n=n>>1;
        }
        return result;
    }
public:
    double myPow(double x, int n) {
        return helper(x,1LL*n);
    }
};

int main(){

return 0;
}