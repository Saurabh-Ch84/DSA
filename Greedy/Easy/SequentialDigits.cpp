#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    int numOfDigit(int n){
        int count=0;
        while(n){
            count++;
            n=n/10;
        }
        return count;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vint res;
        int lb=numOfDigit(low), ub=numOfDigit(high);
        for(int num=lb;num<=ub;num++){
            for(int st=1;st<10;st++){
                int number=0, d=st, len;
                for(len=0; len<num && d<10 ;len++)
                    number=number*10+(d++);
                if(number<=high && number>=low && len==num)
                    res.push_back(number);
            }
        }
        return res;
    }
};

int main(){

return 0;
}