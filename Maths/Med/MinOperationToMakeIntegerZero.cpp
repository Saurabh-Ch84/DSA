#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isFeasible(int n,long long num){
        if(num<0) return false;
        int count=0;
        while(num){
            num=num & (num-1);
            count++;
        }
        return count<=n;
    }
public:
    int makeTheIntegerZero(int num1, int num2) {
        int n=1;
        while(n<=60){
            long long num=1LL*num1-1LL*n*num2;
            if(isFeasible(n,num)) return n;
            n++;
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.makeTheIntegerZero(3,0);
    return 0;
}