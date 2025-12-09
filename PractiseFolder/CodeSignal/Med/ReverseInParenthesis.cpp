#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

/*

### Medium | Codewriting | 300

Write a function that reverses characters in (possibly nested) parentheses in the input string.

Input strings will always be well-formed with matching ()s.

#### Example

- For `inputString = "(bar)"`, the output should be  
  `reverseInParentheses(inputString) = "rab"`

- For `inputString = "foo(bar)baz"`, the output should be  
  `reverseInParentheses(inputString) = "foorabbaz"`

- For `inputString = "foo(bar)baz(blim)"`, the output should be  
  `reverseInParentheses(inputString) = "foorabbazmilb"`

- For `inputString = "foo(bar(baz))blim"`, the output should be  
  `reverseInParentheses(inputString) = "foobazrabblim"`
*/

class Solution{
        public:
    string reverseInParenthesis(string str){
        string result;
        stack<string> s;
        for(char ch: str){
            if(ch=='('){
                s.push(result);
                result="";
            }
            else if(ch==')'){
                reverse(result.begin(),result.end());
                result=s.top()+result;
                s.pop();
            }
            else result+=ch;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.reverseInParenthesis("foo(bar(baz))blim")<<endl;
    cout<<s.reverseInParenthesis("foo(bar)(baz)blim")<<endl;
    cout<<s.reverseInParenthesis("(bar)")<<endl;
    cout<<s.reverseInParenthesis("foo(bar)baz")<<endl;
return 0;
}