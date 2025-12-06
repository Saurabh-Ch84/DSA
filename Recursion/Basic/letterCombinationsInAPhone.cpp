#include<iostream>
#include<vector>
using namespace std;

using vs = vector<string> ; 
class Solution {
    void recursion(int i,int n,string &digits,vs &keyPad,string &temp,vs &ans){
        if(i>=n){
            ans.push_back(temp);
            return ;
        }
        int j=digits[i]-'0';
        for(char letter: keyPad[j]){
            temp.push_back(letter);
            recursion(i+1,n,digits,keyPad,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vs keyPad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vs ans;
        string temp;
        int n=digits.length();
        recursion(0,n,digits,keyPad,temp,ans);
        return ans;
    }
};

int main(){

return 0;
}