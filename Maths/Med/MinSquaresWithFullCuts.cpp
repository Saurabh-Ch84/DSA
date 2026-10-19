#include<bits/stdc++.h>
using namespace std;

class Solution {
    int recursion(int n,int m){
        if(!n) return 0;
        if(m>n) swap(n,m);
        return (n/m)+recursion(n%m,m);
    }
  public:
    int minSquares(int n, int m) {
        // code here
        return recursion(n,m);
    }
};

int main(){

return 0;
}