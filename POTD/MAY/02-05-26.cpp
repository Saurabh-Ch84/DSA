#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        // code here
        int setBit=0;
        for(int i=0;i<31;i++){
            int bit=(n & (1<<i));
            if(bit){
                if(setBit) return -1;
                setBit=i+1;
            }
        }
        return (setBit? setBit: -1);
    }
};

class Solution {
    bool isGood(int n){
        bool flag=false;
        while(n){
            int d=n%10;
            if(d==3 || d==4 || d==7)
                return false;
            if(d==2 || d==6 || d==5 || d==9) 
                flag=true;
            n=n/10;
        }
        return flag;
    }
public:
    int rotatedDigits(int n){
        int a=0;
        for(int i=1;i<=n;i++){
            if(isGood(i)) a++;
        }
        return a;
    }
};

int main(){

return 0;
}