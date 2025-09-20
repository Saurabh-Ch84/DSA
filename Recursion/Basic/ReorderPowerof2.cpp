#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool isPowerOf2(string &num){
        if(num.empty() || num[0]=='0') return false;
        int n=stoi(num);
        return (n&(n-1))==0;
    }

    bool recursion(string &num,int m,int j){
        if(isPowerOf2(num))
            return true;
        if(j>=m) 
            return false;
        for(int i=j;i<m;i++){
            swap(num[i],num[j]);
            if(recursion(num,m,j+1))
                return true;
            swap(num[i],num[j]);
        }
        return false;
    }

    string sortDigits(int n){
        string num=to_string(n);
        sort(begin(num),end(num));
        return num;
    }
        public:

    bool reorderedPowerOf2Brute(int n) {
        string num=to_string(n);
        int m=num.size();
        return recursion(num,m,0);
    }

    bool reorderedPowerOf2Optimal(int n) {
        string num=sortDigits(n);
        for(int i=0;i<31;i++){
            string temp=sortDigits(1<<i);
            if(temp==num)
                return true;
        }
        return false;
    }
};


int main(){
    Solution s;
    cout<<s.reorderedPowerOf2Optimal(1204);
return 0;
}