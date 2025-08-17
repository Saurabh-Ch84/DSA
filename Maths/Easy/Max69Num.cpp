#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string number=to_string(num);
        int n=number.length();
        for(int i=0;i<n;i++){
            if(number[i]=='6'){
                number[i]='9';
                break;
            }
        }
        int res=stoi(number);
        return res;
    }
};

int main(){

return 0;
}