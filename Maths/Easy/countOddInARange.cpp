#include<iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high){
        int left=low/2;
        int right=(high+1)/2;
        return right-left;
    }
};

int main(){

return 0;
}