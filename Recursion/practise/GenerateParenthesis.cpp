#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(int i,int j,int n,string &temp,vector<string> &ans){
        if(i+j==2*n){
            ans.push_back(temp);
            return ;
        }
        if(n>i){
            temp.push_back('(');
            recursion(i+1,j,n,temp,ans);
            temp.pop_back();
        }
        if(i>j){
            temp.push_back(')');
            recursion(i,j+1,n,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        recursion(0,0,n,temp,ans);
        return ans;
    }
};

int main(){

return 0;
}