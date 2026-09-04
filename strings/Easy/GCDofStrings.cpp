#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isStrDivisible(string &str,string &gcd){
        if(gcd==str) return 1;
        int i=0, n=str.size(), m=gcd.size();
        while(i<n){
            string temp=str.substr(i,m);
            if(temp!=gcd) break;
            i+=m;
        }
        return (i==n);
    }
public:
    string gcdOfStrings(string str1,string str2) {
        if(str1.size()<str2.size()) return gcdOfStrings(str2,str1);
        int n=str1.size(), m=str2.size();
        for(int len=m;len>0;len--){
            string gcd=str2.substr(0,len);
            if(isStrDivisible(str2,gcd) && isStrDivisible(str1,gcd)) 
                return gcd;
        }
        return "";
    }
};

int main(){

return 0;
}