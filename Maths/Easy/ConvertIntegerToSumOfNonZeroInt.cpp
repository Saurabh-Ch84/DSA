#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isNonZero(int num){
        while(num){
            int d=num%10;
            if(d==0) return false;
            num=num/10;
        }
        return true;
    }
public:
    //Brute
    vector<int> getNoZeroIntegers1(int n) {
        int n_=n/2;
        for(int i=1;i<=n_;i++){
            int a=i,b=n-i;
            if(isNonZero(a) && isNonZero(b))
                return {a,b};
        }
        return {-1,-1};
    }

    //Optimal
    vector<int> getNoZeroIntegers2(int n) {
        int a=n,b=0,place=1;
        while(n>1){
            int take=1;
            if(n%10==1) take=2;
            a=a-take*place;
            b=b+take*place;
            n=(n-take)/10;
            place=place*10;
        }
        return {a,b};
    }
};

int main(){
    Solution s;
    vector<int> ans=s.getNoZeroIntegers2(100);
    cout<<ans[0]<<" "<<ans[1]<<endl;
return 0;
}