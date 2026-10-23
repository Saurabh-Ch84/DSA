#include<iostream>
using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int num=0;
        for(int i=0;i<32;i++){
            int bit=(n>>i) & 1;
            num=(num<<1) | bit;
        }
        return num;
    }
};

int main(){

return 0;
}