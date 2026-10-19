#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        while(sum){
            int d=min(sum,9);
            res.push_back('0'+d);
            if(res.size()>num) return "";
            sum-=d;
        }
        while(res.size()!=num){
            res.push_back('0');
        }
        return res;
    }
};

int main(){

return 0;
}