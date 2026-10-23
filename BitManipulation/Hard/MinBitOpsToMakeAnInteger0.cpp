#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using un_ss = unordered_set<string>;

class Solution1 {
public:
    int minimumOneBitOperations(int n) {
        if(n<=1) return n;
        vector<long long> f(31,0);
        f[0]=1; // if only 0th bit is set then only a operation-1 is needed!
        for(int i=1;i<31;i++)
            f[i]=2*f[i-1]+1;
        
        int ops=0,sign=1;
        // moving from left to right is beneficial for min ans.
        for(int i=30;i>=0;i--){
            int ithBit=(n & (1<<i));
            if(!ithBit) continue;
            ops+=f[i]*sign;
            sign=sign*(-1);
        }
        
        return ops;
    }
};

class Solution2 {
    string decToBin(int n){
        string binary(32,'0');
        for(int i=0;i<32;i++){
            if(n & (1U<<i)) 
                binary[32-i-1]='1';
        }
        return binary;
    }

    void toggleBit(string &bin,int idx){
        char bit=bin[idx];
        bin[idx]=(bit=='1')? '0':'1';
    }

    void operation2(string &bin,queue<string> &q,un_ss &hashSet){
        for(int i=31;i>0;i--){
            if(bin[i]=='1'){
                toggleBit(bin,i-1);
                if(!hashSet.count(bin)){
                    q.push(bin);
                    hashSet.insert(bin);
                }
                return ;
            }
        }
    }

    void operation1(string &bin,queue<string> &q,un_ss &hashSet){
        toggleBit(bin,31);
        if(!hashSet.count(bin)){
            q.push(bin);
            hashSet.insert(bin);
        }
        toggleBit(bin,31);
    }
public:
    int minimumOneBitOperations(int n){
        un_ss hashSet;
        string binary=decToBin(n),target(32,'0');
        queue<string> q;
        q.push(binary);
        hashSet.insert(binary);
        int ops=0;

        while(!q.empty()){
            int sz=q.size();
            while(sz){
                string bin=q.front();q.pop();
                if(bin==target) return ops;
                operation1(bin,q,hashSet);
                operation2(bin,q,hashSet);
                sz--;
            }
            ops++;
        }
        return ops;
    }
};

int main(){

return 0;
}