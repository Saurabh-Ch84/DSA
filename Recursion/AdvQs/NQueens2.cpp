#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(vector<bool> &r,vector<bool> &d,vector<bool> &s,int col,int n,int &count){
        if(col==n){
            count++;
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(!r[i] && !d[n+i-col-1] && !s[i+col])
            {
                r[i]=true,d[n+i-col-1]=true,s[i+col]=true;
                recursion(r,d,s,col+1,n,count);
                r[i]=false,d[n+i-col-1]=false,s[i+col]=false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<bool> row(n,false),dexter(2*n-1,false),sinister(2*n-1,false);
        int count=0;
        recursion(row,dexter,sinister,0,n,count);
        return count;
    }
};

int main(){

return 0;
}