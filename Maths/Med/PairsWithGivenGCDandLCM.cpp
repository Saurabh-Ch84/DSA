#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        if(y%x) return 0;
        long long lcmByGcd=y/x;
        int k=0;
        for(int i=2;i*i<=lcmByGcd;i++){
            if(lcmByGcd%i==0){
                k++;
                while(lcmByGcd%i==0){
                    lcmByGcd=lcmByGcd/i;
                }
            }
        }
        if(lcmByGcd>1) k++;
        return (1<<k);
    }
};


int main(){

return 0;
}