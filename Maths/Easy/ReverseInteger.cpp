#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long n=1LL*x;
        long long num=0;
        while(n){
            int d=n%10;
            num=num*10+d;
            if(num>INT_MAX || num<INT_MIN) return 0;
            n=n/10;
        }
        return (int)num;
    }
};

class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while (x != 0) {
            int d = x % 10;
            // check overflow before multiplying
            if (num > INT_MAX/10 || (num == INT_MAX/10 && d > 7)) return 0;
            if (num < INT_MIN/10 || (num == INT_MIN/10 && d < -8)) return 0;
            num = num * 10 + d;
            x /= 10;
        }
        return num;
    }
};


int main(){

return 0;
}