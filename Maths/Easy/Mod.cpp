#include<iostream>
using namespace std;

class Solution {
  public:
    int modmul(int a, int b, int M) {
        // code here
        return ((a%M)*(b%M))%M;
    }
};

int main(){

return 0;
}