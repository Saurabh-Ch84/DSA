#include<iostream>
using namespace std;

class Solution {
        public:
    long long flowerGame(int n, int m) {
        return (1LL*n*m)/2;
    }
};

int main(){
    Solution s;
    cout<<s.flowerGame(3,2);
return 0;
}