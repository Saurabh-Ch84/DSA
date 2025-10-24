#include<iostream>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int n=s.length();
        while(n>2){
            for(int i=0;i<n-1;i++){
                int a=s[i]-'0';
                int b=s[i+1]-'0';
                s[i]=(a+b) % 10+'0';
            }
            n--;
        }
        return s[0]==s[1];
    }
};

int main(){

return 0;
}