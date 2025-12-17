#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    int factorial(int n){
        long long fact=1;
        const int MOD=1e9+7;
        for(int i=1;i<=n;i++){
            fact=(fact*i)%MOD;
        }
        return fact;
    }
public:
    int countPermutations(vector<int>& complexity) {
        sort(complexity.begin()+1,complexity.end());
        if(complexity[0]>=complexity[1]) return 0;
        int n=complexity.size();
        return factorial(n-1);
    }
};

int main(){

return 0;
}