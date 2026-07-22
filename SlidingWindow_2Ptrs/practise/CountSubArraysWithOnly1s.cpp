#include<iostream>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        int left=0,right=0,n=s.length();
        int count=0,MOD=1e9+7;
        while(right<n){
            if(s[right]=='1'){
                count=(count+(right-left+1))%MOD;
                right++;
            }
            while(s[right]=='0'){
                right++;
                left=right;
            }
        }
        return count;
    }
};

int main(){

return 0;
}