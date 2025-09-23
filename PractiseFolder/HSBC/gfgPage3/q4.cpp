#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/*
    Q1.Reduce to one- we were given N and we need to return the number of operations required 
    to make that N one,  we could perform full operations- 
    choose x such that x<N and N%x==0 or perform N-1.

    Q2. Armstrong number.
*/

class Solution1{
    void spfCal(vector<int> &spf,int N){
        for(int i=0;i<=N;i++) spf[i]=i;
        for(int i=2;i*i<=N;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=N;j+=i)
                    if(spf[j]==j) spf[j]=i;
            }
        }
    }
        public:
    int q1(int N){
        vector<int> spf(N+1);
        spfCal(spf,N);
        int ops=0;
        while(N>1){
            if(spf[N]<N)
                N=N/spf[N];
            else 
                N=N-1;
            ops++;
        }
        return ops;
    }
};


void print(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}


class Solution2{
    int binExpo(int base,int exp){
        int result=1;
        while(exp){
            if(exp%2==1) result*=base;
            base*=base;
            exp/=2;
        }
        return result;
    }

    int countDigits(int num){
        if(num==0) return 1;
        int digits=0;
        while(num){
            num/=10;
            digits++;
        }
        return digits;
    }

    bool isArmstrong(int num,int exp){
        int sum=0,temp=num;
        while(temp){
            int digit=temp%10;
            sum+=binExpo(digit,exp);
            temp/=10;
        }
        return sum==num;
    }
        public:
    vector<int> q2(int lb,int ub){
        vector<int> res;
        int exp,count=-1;
        for(int i=lb;i<=ub;i++){
            if(count<=i){
                exp=countDigits(i);
                count=binExpo(10,exp);
            }
            if(isArmstrong(i,exp))
                res.push_back(i);
        }
        return res;
    }
};

int main(){
    Solution2 s;
    print(s.q2(0,10000));
    
    Solution1 s_;
    cout<<s_.q1(100);
return 0;
}