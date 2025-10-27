#include<iostream>
using namespace std;

class Solution {
    int calSum(int week,int days){
        return ((days)*(days+1))/2+(week*days);
    }
public:
    int totalMoney(int n) {
        int totalSum=0,bound=n/7;
        for(int week=0;week<=bound;week++){
            int days=min(n-7*week,7);
            int weekSum=calSum(week,days);
            totalSum+=weekSum;
        }
        return totalSum;
    }
};

int main(){

return 0;
}