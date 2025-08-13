#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> hashSet;
        hashSet.insert(1);
        long num = 1;
        while (n--) {
            num = *hashSet.begin();
            hashSet.erase(hashSet.begin());
            hashSet.insert(num * 2);
            hashSet.insert(num * 3);
            hashSet.insert(num * 5);
        }
        return (int) num;
    }
};


int main(){
    int num=9;
    Solution s;
    cout<<s.nthUglyNumber(num);
return 0;
}