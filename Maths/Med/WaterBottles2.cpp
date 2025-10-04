#include<iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles=numBottles,empty=0,bottlesDrunk=0;

        while(fullBottles>0){
            bottlesDrunk+=fullBottles;
            empty+=fullBottles;
            fullBottles=0;
            while(empty>=numExchange){
                fullBottles++;
                empty-=numExchange;
                numExchange++;
            }
        }

        return bottlesDrunk;
    }
};

int main(){
    Solution s;
    cout<<s.maxBottlesDrunk(13,6);
return 0;
}