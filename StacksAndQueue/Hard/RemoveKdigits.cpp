#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        string number="";
        stack<char> mIStack;
        for(int i=0;i<n;i++)
        {
            char digit=num[i];
            while(!mIStack.empty() && digit<mIStack.top() && k){
                mIStack.pop();
                k--;
            }
            mIStack.push(digit);
        }
        //Remove digits useful in case of descending digits
        while (k-- > 0 && !mIStack.empty()) mIStack.pop();
        //construct number
        while(!mIStack.empty()){
            number+=mIStack.top();
            mIStack.pop();
        }
        //remove leading zero's
        while(number.length() && number.back()=='0') number.pop_back();
        //reverse to get the correct answer
        reverse(number.begin(),number.end());
        //return 0 if or number
        return (number=="")?"0":number;
    }
};

int main(){

return 0;
}