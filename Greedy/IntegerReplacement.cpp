#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// greedy
class Solution1 {
public:
    int integerReplacement(int n) {
        long long num = n; // To avoid overflow for INT_MAX
        int steps = 0;
        while (num != 1) {
            if (num % 2 == 0) {
                num >>= 1;
            } else {
                if (num == 3 || (num & 2) == 0) {
                    num--;
                } else{
                    num++;
                }
            }
            steps++;
        }
        return steps;
    }
};

class Solution2 {
    int memoization(long long n,unordered_map<long long,int> &dp){
        if(n==1) return 0;
        if(dp.count(n)) return dp[n];
        int divBy2=INT_MAX,addOne=INT_MAX,minusOne=INT_MAX;
        if(n%2==0) divBy2=1+memoization(n/2,dp);
        else{
            addOne=1+memoization(n+1,dp);
            minusOne=1+memoization(n-1,dp);
        }
        return dp[n]=min({divBy2,addOne,minusOne});
    }
public:
    int integerReplacement(int n){
        unordered_map<long long,int> dp;
        return memoization((long long)n,dp);
    }
};


int main(){
    Solution1 s;
    cout<<s.integerReplacement(10)<<endl;
return 0;
}