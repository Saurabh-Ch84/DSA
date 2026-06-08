#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isMonobit(int num){
        return (num==0 || (num+1 & num)==0);
    }
public:
    int countMonobit(int n) {
        int a=0;
        for(int i=0;i<=n;i++)
            a+=isMonobit(i);
        return a;
    }
};

int main(){

return 0;
}