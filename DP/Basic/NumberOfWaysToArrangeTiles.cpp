#include<iostream>
using namespace std;

class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        if(n<=2) return n;
        int a=1,b=2;
        for(int i=2;i<n;i++){
            int t=b;
            b=a+b;
            a=t;
        }
        return b;
    }
};

int main(){

return 0;
}