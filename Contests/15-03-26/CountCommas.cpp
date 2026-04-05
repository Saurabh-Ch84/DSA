#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<int> comma={0,0,0,0,1,1,1,2,2,2,3};
public:
    int countCommas(int n) {
        int digit=0, num=n;
        do{
            num=num/10;
            digit++;
        }while(num);
        
        int count=0, lb=1000, ub=min(10*lb-1,n);
        for(int d=4;d<=digit;d++){
            count+=(ub-lb+1)*comma[d];
            if(ub==n) break;
            lb=lb*10;
            ub=min(10*lb-1,n);
        }
        return count;
    }
};

int main(){

return 0;
}