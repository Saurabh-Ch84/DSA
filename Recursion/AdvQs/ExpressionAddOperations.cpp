#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(vector<string> &res,string &s,string expression,
                    long target,long sum,long prev,int i,int n)
    {
        if(i==n && sum==target){
            res.push_back(expression);
            return ;
        }
        for(int j=i;j<n;j++){
            if(j>i && s[i]=='0') 
                return ;
            long num=stol(s.substr(i,j-i+1));
            if(i==0)
                recursion(res,s,expression+s.substr(i,j-i+1),target,num,num,j+1,n);
            else{
                recursion(res,s,expression+'+'+s.substr(i,j-i+1),target,sum+num,num,j+1,n);
                recursion(res,s,expression+'-'+s.substr(i,j-i+1),target,sum-num,-num,j+1,n);
                recursion(res,s,expression+'*'+s.substr(i,j-i+1),target,sum-prev+(prev*num),prev*num,j+1,n);
            }
        }
    }
  public:
    vector<string> findExpr(string &s, int target) {
        // code here
        vector<string> res;
        recursion(res,s,"",(long)target,0L,0L,0,s.length());
        return res;
    }
};

int main(){

return 0;
}