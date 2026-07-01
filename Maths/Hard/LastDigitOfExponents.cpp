#include<bits/stdc++.h>
using namespace std;

class Solution {
    int modOfLargeNums(const string &str){
        int maxCycleLength=4,num=0;
        for(char digit:str)
            num=(num*10+(digit-'0'))%maxCycleLength;
        return num;
    }
  public:
    int getLastDigit(string a, string b) {
        // code here
        if(b=="0") return 1;
        int lastDigit=a.back()-'0';
        int expo=modOfLargeNums(b);
        if(expo==0) expo=4;
        
        int res=1;
        for(int i=0;i<expo;i++)
            res=(res*lastDigit)%10;
        return res;
    }
};

int main(){

return 0;
}