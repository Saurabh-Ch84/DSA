#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    string operationAdd(string s,int a,int n){
        for(int i=1;i<n;i+=2){
            int num=s[i]-'0';
            int newNum=(num+a)%10;
            s[i]=newNum+'0';
        }
        return s;
    }

    string operationRotate(string s,int b,int n){
        reverse(s.begin(),s.begin()+(n-b));
        reverse(s.begin()+(n-b),s.end());
        reverse(s.begin(),s.end());
        return s;
    }

    void DFS(int a,int b,int n,string s,set<string> &hashSet){
        if(hashSet.count(s)) return ;
        hashSet.insert(s);
        string s1=operationAdd(s,a,n);
        DFS(a,b,n,s1,hashSet);
        string s2=operationRotate(s,b,n);
        DFS(a,b,n,s2,hashSet);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        int n=s.length();
        set<string> hashSet;
        DFS(a,b,n,s,hashSet);
        return *hashSet.begin();
    }
};

int main(){

return 0;
}