#include<iostream>
using namespace std;

class Solution1 {
public:
    bool checkValidString(string s) {
        int maxOpen=0,minOpen=0,n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                maxOpen++;
                minOpen++;
            }
            else if(ch=='*'){
                maxOpen++;
                minOpen--;
            }
            else{
                minOpen--;
                maxOpen--;
            }
            if(maxOpen<0) return false;
            if(minOpen<0) minOpen=0;
        }
        return minOpen==0;
    }
};

class Solution2 {
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

class Solution3 {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int leftBalance=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                leftBalance--;
                if(leftBalance<0) 
                    return 0;
            }
            else leftBalance++;
        }
        if(leftBalance==0) return 1;
        int rightBalance=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                rightBalance--;
                if(rightBalance<0) 
                    return 0;
            }
            else rightBalance++;
        }
        return 1;
    }
};

int main(){
    Solution3 *s=new Solution3();
    cout<<s->checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())")<<endl;
return 0;
}