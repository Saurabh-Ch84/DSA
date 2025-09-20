#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a,int b){
        while(b){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> s;
        for(int &num:nums){
            long long a=(long long)num;
            while(!s.empty() && gcd(s.back(),a)>1){
                long long b=s.back();
                s.pop_back();
                a=(a*b*1LL)/gcd(a,b);
            }
            s.push_back((int)a);
        }
        return s;
    }
};

int main(){
    Solution s;
return 0;
}