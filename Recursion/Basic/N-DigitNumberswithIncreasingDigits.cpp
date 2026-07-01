#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    void recursion(int num,int pd,int i,int n,vint &res){
        if(i==n){
            res.push_back(num);
            return;
        }
        for(int d=pd+1;d<=9;d++){
            int temp=num*10+d;
            recursion(temp,d,i+1,n,res);
        }
    }
  public:
    vint increasingNumbers(int n) {
        // code here
        if(n>=10) return {};
        vint res;
        if(n==1) res.push_back(0);
        recursion(0,0,0,n,res);
        return res;
    }
};

int main(){

return 0;
}