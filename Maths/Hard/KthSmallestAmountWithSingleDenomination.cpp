#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long gcd(long long a,long long b){
        while(b){
            long long t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    bool check(long long mid,int k,int n,vector<int> &coins){
        long long count=0;
        for(int exp=1;exp<(1<<n);exp++){
            int order=0;
            long long lcm=1;
            for(int i=0;i<n;i++){
                if(exp & (1<<i)){
                    order++;
                    lcm=lcm/gcd(lcm,coins[i])*coins[i];
                }
            }
            if(order%2==0) count=count-mid/lcm;
            else count=count+mid/lcm;
        }
        return (count>=k);
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size(), mini=*min_element(coins.begin(),coins.end());
        long long low=mini, high=1LL*k*mini, res=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(mid,k,n,coins)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};

int main(){

return 0;
}