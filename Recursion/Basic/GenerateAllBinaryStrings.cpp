#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(vector<string> &result,string &temp,int n){
        if(temp.length()==n){
            result.push_back(temp);
            return ;
        }
        temp.push_back('0');
        recursion(result,temp,n);
        temp.pop_back();
        
        temp.push_back('1');
        recursion(result,temp,n);
        temp.pop_back();
    }
  public:
    vector<string> binstr(int n) {
        // code here
        vector<string> result;
        string temp;
        recursion(result,temp,n);
        return result;
    }
};

int main(){

return 0;
}