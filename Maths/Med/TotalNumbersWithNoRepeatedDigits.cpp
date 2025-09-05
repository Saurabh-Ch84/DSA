#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Given a range L,R find total such numbers in the given range such that they have no repeated digits. 
    For example: 12 has no repeated digit. 22 has repeated digit. 102, 194 and 213 have no repeated digit. 
    212, 171 and 4004 have repeated digits. 
*/

class Solution{
    vector<int> prefixArr;
    void precompute(int maxi){
        prefixArr.resize(maxi+1);
        prefixArr[0]=1;
        for(int i=1;i<=maxi;i++)
            prefixArr[i]=isNotRepeatingNum(i)+prefixArr[i-1];
    }

    bool isNotRepeatingNum(int num){
        unordered_set<int> hashSet;
        while(num>0){
            int digit=num%10;
            if(hashSet.insert(digit).second==false) 
                return false;
            num=num/10;
        }
        return true;
    }
        public:
    Solution(){
        precompute(10000);
    }

    int brute(int L,int R){
        int ans=0;
        for(int i=L;i<=R;i++)
            ans+=isNotRepeatingNum(i);
        return ans;
    }

    int better(int L,int R){
        return prefixArr[R]-prefixArr[L-1];
    }
};

int main(){
    Solution s;
    int lb1=1,ub1=100;
    int lb2=12,ub2=19;
    int lb3=10,ub3=200;
    cout<<s.brute(lb1,ub1)<<endl;
    cout<<s.brute(lb2,ub2)<<endl;
    cout<<s.brute(lb3,ub3)<<endl;

    cout<<s.better(lb1,ub1)<<endl;
    cout<<s.better(lb2,ub2)<<endl;
    cout<<s.better(lb3,ub3)<<endl;
return 0;
}