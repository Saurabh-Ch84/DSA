#include<iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int rem=0,bottles=numBottles;
        while(numBottles){
            int temp=rem+numBottles;
            numBottles=(temp)/numExchange;
            rem=temp % numExchange;
            bottles+=numBottles;
        }
        return bottles;
    }
};

int main(){
    
return 0;
}