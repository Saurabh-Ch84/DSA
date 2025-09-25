#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0) return "undefined";
        bool flag=false;
        if(numerator<0 && denominator>0) flag=true;
        if(numerator>0 && denominator<0) flag=true;

        string quotient;

        long long dividend=abs((long long) numerator);
        long long divisor=abs((long long) denominator);

        if(dividend==0) return "0";

        long long temp=divisor;

        while(temp%2==0) temp=temp/2;
        while(temp%5==0) temp=temp/5;

        if(temp==1){
            if(dividend % divisor==0){
                quotient=to_string(dividend/divisor);
            }
            else{
                long long rem=dividend % divisor;
                int q=dividend/divisor;
                quotient+=to_string(q)+'.';

                while(rem!=0){
                    rem=rem*10;
                    q=rem/divisor;
                    rem=rem % divisor;
                    quotient+=to_string(q);
                }
            }
        }
        else{
            long long rem=dividend % divisor;
            int q=dividend/divisor;
            quotient+=to_string(q)+'.';

            unordered_map<int,int> hashMap;

            string dummy;
            int len=0;
            while(hashMap.find(rem)==hashMap.end()){
                hashMap[rem]=len;
                len++;
                rem=rem*10;
                q=rem/divisor;
                rem=rem % divisor;
                dummy+=to_string(q);
            }

            for(int i=0;i<hashMap[rem];i++)
                quotient+=dummy[i];
                
            quotient+='(';

            for(int i=hashMap[rem];i<len;i++)
                quotient+=dummy[i];
            
            quotient+=')';

        }
        if(flag) quotient='-'+quotient;
        return quotient;
    }
};

int main(){

return 0;
}