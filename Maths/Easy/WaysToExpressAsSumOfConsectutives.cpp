#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mathematicalHelper(int sN){
        int ub=2*sN, count=0;
        for(long n=2;ub+n>n*n;n++){
            int numerator=ub+n-n*n;
            int denominator=2*n;
            if((numerator%denominator)==0)
                count++;
        }
        return count;
    }
  public:
    int getCount(int n) {
        // code here
        return mathematicalHelper(n);
    }
};

int main(){

return 0;
}