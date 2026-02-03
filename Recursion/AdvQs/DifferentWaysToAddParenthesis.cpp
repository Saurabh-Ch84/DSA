#include<iostream>
#include<vector>
using namespace std;

using vi = vector<int> ;
class Solution {
    bool isOperator(char sign){
        return (sign=='+' || sign=='*' || sign=='-');
    }
    vi recursion(string expression){
        vi result;
        for(int i=0;i<expression.size();i++){
            if(isOperator(expression[i])){
                char sign=expression[i];
                vi leftExp=recursion(expression.substr(0,i));
                vi rightExp=recursion(expression.substr(i+1));
                for(int &x: leftExp){
                    for(int &y: rightExp){
                        if(sign=='+') result.push_back(x+y);
                        else if(sign=='*') result.push_back(x*y);
                        else result.push_back(x-y);
                    }
                }
            }
        }
        if(result.empty()) 
            result.push_back(stoi(expression));
        return result;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return recursion(expression);
    }
};

int main(){

return 0;
}