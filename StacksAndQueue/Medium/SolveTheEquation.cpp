#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int n=equation.size(), numerator=0, denominator=0, ptr=0; // numerator is the constant term, denominator is the coefficient of x.
        bool equalToFound=false; // we are using this flag to keep track of whether we have found the equal sign or not, so that we can add or
        // subtract the constant term and the coefficient of x accordingly.
        stack<int> helperStack; // we are using a stack to keep track of the sign of the coefficient of x and the constant term
        while(ptr<n){
            // if the helperStack is empty, we push 1 into it, which is the default coefficient of x.
            if(helperStack.empty()) helperStack.push(1);
            char ch=equation[ptr];
            if(ch=='='){
                // we have found the equal sign, so we need to change the sign of the coefficient of x and the constant term.
                equalToFound=true;
                ptr++;
            }
            else if(ch=='x'){
                // we have found an 'x', so we need to add it to the denominator or subtract it from the denominator 
                // based on the is equalToFound flag.
                if(equalToFound) denominator-=helperStack.top();
                else denominator+=helperStack.top();
                helperStack.pop();
                ptr++;
            }
            else if(ch=='+' || ch=='-'){
                // we need to change the sign of the coefficient of x and the constant term, so we multiply the top element 
                // of the helperStack by the respective sign, the resultant sign is managed by is equalToFound.
                int temp=(ch=='+'? 1:-1)*helperStack.top();
                helperStack.pop();
                helperStack.push(temp);
                ptr++;
            }
            else{
                // we are at a number, so we need to extract the number from the string and multiply it with the top element 
                // of the helperStack to get the prev correct sign.
                int num=0;
                while(ptr<n && isdigit(equation[ptr])){
                    num=num*10+(equation[ptr]-'0');
                    ptr++;
                }
                num=num*helperStack.top();
                helperStack.pop();
                // if we have found an 'x' after the number, then we need to add it to the denominator or subtract it from the denominator
                // based on the is equalToFound flag.
                if(ptr<n && equation[ptr]=='x')
                    helperStack.push(num);
                else{
                    // we have found a constant term, so we need to add it to the numerator or subtract it 
                    // from the numerator based on the is equalToFound flag.
                    if(equalToFound) numerator+=num;
                    else numerator-=num;
                }
            }
        }
        // if the denominator is 0 and the numerator is also 0, then we have infinite solutions,
        if(denominator==0 && numerator==0) return "Infinite solutions";
        // if the denominator is 0 and the numerator is not 0, then we have no solution.
        if(denominator==0) return "No solution";
        // if the denominator is not 0, then we have a unique solution, so we return the value of x.
        return "x="+to_string(numerator/denominator);
    }
};

int main(){

return 0;
}