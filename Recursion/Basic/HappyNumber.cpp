#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
    bool recursion(int n,unordered_set<int> &hashSet){
        if(n==1) return true;
        if(hashSet.count(n)) return false;
        hashSet.insert(n);
        int n_=0;
        while(n){
            int d=n%10;
            n/=10;
            n_+=d*d;
        }
        return recursion(n_,hashSet);
    }
public:
    bool isHappy(int n) {
        unordered_set<int> hashSet;
        return recursion(n,hashSet);
    }
};

int main(){

return 0;
}