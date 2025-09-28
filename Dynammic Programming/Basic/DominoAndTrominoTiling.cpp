#include<iostream>
using namespace std;

class Solution {
public:
    int numTilings(int n) {
        if(n<=2) return n;

        const int MOD=1e9+7;
        int a=1,b=1,c=2,d;

        for(int i=3;i<=n;i++){
            d=((2*c)%MOD+a)%MOD;
            a=b;
            b=c;
            c=d;
        }
        
        return d;
    }
};

int main(){

return 0;
}