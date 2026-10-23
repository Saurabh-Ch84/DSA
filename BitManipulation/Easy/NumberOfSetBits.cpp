#include<iostream>
using namespace std;

class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        /*
        for(int i=0;i<32;i++){
            count += n & 1;
            n=n>>1;
        }
        */
        while(n){
            n=n & (n-1);
            count++;
        }
        return count;
    }
};

int main(){

return 0;
}