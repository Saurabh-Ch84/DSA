#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int ptr=0,lastIdx=n-1;
        while(ptr<n){
            if(ptr==lastIdx) return true;
            if(bits[ptr]) ptr+=2;
            else ptr+=1;
        }
        return false;
    }
};

int main(){

return 0;
}