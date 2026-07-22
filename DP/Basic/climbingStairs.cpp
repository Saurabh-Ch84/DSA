#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int ans;
        int left=1,right=2;
        for(int i=3;i<=n;i++)    
        {
            ans=left+right;
            left=right;
            right=ans;
        }
        return ans;
    }
};

int main(){

return 0;
}