#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int trials=(minutesToTest/minutesToDie)+1, pigs=0;
        while(pow(trials,pigs)<buckets)
            pigs++;
        return pigs;
    }
};

int main(){

return 0;
}