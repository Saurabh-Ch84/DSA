#include<iostream>
using namespace std;

class Solution {
public:
    int andInRange(int l, int r) {
        int count = 0;
        while (l != r) {
            l=l>>1;
            r=r>>1;
            count++;
        }
        return l<<count;
    }
};


int main(){

return 0;
}