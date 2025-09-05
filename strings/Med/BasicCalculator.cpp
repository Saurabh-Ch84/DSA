#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n=s.length(),ptr=0;
        int result=0,number=0,sign=1;
        stack<int> st;
        while(ptr<n){
            if(isdigit(s[ptr])){
                number=(number*10)+(s[ptr]-'0');
            }
            else if(s[ptr]=='-' || s[ptr]=='+'){
                result=result+sign*number;
                number=0;
                sign=(s[ptr]=='-')?-1:1;
            }
            else if(s[ptr]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
            else if(s[ptr]==')'){
                result=result+sign*number;
                number=0;
                int sign_=st.top();st.pop();
                int number_=st.top();st.pop();
                result=result*sign_+number_;
            }
            ptr++;
        }
        result+=number*sign;
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.calculate("1-(  -2)");
return 0;
}