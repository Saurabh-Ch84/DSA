#include<iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s)
    {
        int balance=0;
        int size=s.length();
        for(int i=0;i<size;i++)
        {
            if(s[i]==')')
                balance--;
            else
                balance++;
            if(balance<0)
                return false;
        }

        if(balance==0)
            return true;

        balance=0;
        for(int i=size-1;i>-1;i--)
        {
            if(s[i]=='(')
                balance--;
            else
                balance++;
            if(balance<0)
                return false;
        }

        return true;
    }
};

int main(){
    Solution *s=new Solution();
    cout<<s->checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())")<<endl;
return 0;
}