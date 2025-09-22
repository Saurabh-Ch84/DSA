#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    We have to print alternate prime numbers till N.
*/

class Solution{
    bool isPrime(int num){
        for(int i=2;i*i<=num;i++){
            if(num%i==0)
                return false;
        }
        return true;
    }

    void sieve(vector<bool> &prime,int N){
        for(int i=2;i*i<=N;i++){
            if(prime[i]){
                for(int j=i*i;j<=N;j+=i)
                    prime[j]=false;
            }
        }
    }
        public:
    //Inefficient Brute
    vector<int> qBrute(int N){
        bool flag=true;
        vector<int> res;
        for(int i=2;i<=N;i++){
            if(isPrime(i)){
                if(flag) res.push_back(i);
                flag=!flag;
            }
        }
        return res;
    }

    //Efficient 
    vector<int> qOptimal(int N){
        vector<bool> prime(N+1,true);
        prime[0]=prime[1]=false;
        sieve(prime,N);
        bool flag=true;
        vector<int> res;
        for(int i=0;i<=N;i++){
            if(prime[i]){
                if(flag) res.push_back(i);
                flag=!flag;
            }
        }
        return res;
    }
};

void print(vector<int> nums){
    for(int &num:nums)
        cout<<num<<' ';
    cout<<endl;
}

int main(){
    Solution s;
    print(s.qOptimal(10));
return 0;
}