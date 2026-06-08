#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int>;
class Solution {
    void preprocess(vi &fact){
        for(int i=1;i<10;i++){
            fact[i]=i*fact[i-1];
        }
    }
public:
    bool isDigitorialPermutation(int n) {
        vi fact(10,1);
        preprocess(fact);
        int sum=0, num=n;
        vi freqArr(10,0);
        while(num){
            int d=num%10;
            freqArr[d]--;
            sum+=fact[d];
            num=num/10;
        }
        
        if(sum==n) return true;

        while(sum){
            int d=sum%10;
            freqArr[d]++;
            sum=sum/10;
        }

        for(int i=0;i<10;i++){
            if(freqArr[i]) return false;
        }
        return true;
    }
};

int main(){

return 0;
}