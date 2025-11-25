#include<iostream>
#include<climits>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    bool isOperator(const string &token){
        return (token=="+" || token=="-" || token=="*" || token=="/");
    }
    int solve(int a,int b,const string &token){
        char op=token[0];
        switch(op){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
        }
        return INT_MIN;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &token: tokens){
            if(isOperator(token)){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                int c=solve(a,b,token);
                st.push(c);
            }
            else{
                int num=stoi(token);
                st.push(num);
            }
        }
        return st.top();
    }
};

int main(){

return 0;
}