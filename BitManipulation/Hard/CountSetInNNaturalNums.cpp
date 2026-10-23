#include<iostream>
#include<cmath>
using namespace std;

class Solution {
  public:
    int countSetBits(int n) {
        // code here
        if(!n) return 0;
        int x=(int)log2(n);
        int m=(1<<x);
        return x*(m/2)+(n-m+1)+countSetBits(n-m);
    }
};

int main(){

return 0;
}