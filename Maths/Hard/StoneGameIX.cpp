#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        int zeros=0, ones=0, twos=0;
        for(int i=0;i<n;i++){
            int mod=stones[i]%3;
            if(mod==0) zeros++;
            else if(mod==1) ones++;
            else twos++;
        }
        if(zeros%2==0){
            if(ones && twos) return true;
            return false;
        }  
        else{
            if(abs(ones-twos)>2) return true;
            return false;
        }
    }
};

int main(){

return 0;
}