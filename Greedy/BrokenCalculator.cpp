#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int minCalc=0;
        while(target>startValue){
            bool isEven=!(target%2);
            minCalc++;
            if(isEven) target=target/2;
            else target++;
        }
        minCalc+=(startValue-target);
        return minCalc;
    }
};


int main(){
    Solution s;
    cout<<s.brokenCalc(10,8);
return 0;
}