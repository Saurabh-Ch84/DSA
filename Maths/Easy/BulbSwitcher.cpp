#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int count=0;
        for(long long val=1;val*val<=n;val++)
            count++;
        return count;
    }
};

int main(){

return 0;
}