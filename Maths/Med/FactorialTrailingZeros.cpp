#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n){
            int n_=n/5;
            count+=n_;
            n=n_;
        }
        return count;
    }
};

int main(){

return 0;
}