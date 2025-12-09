#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int count=0,bound=n*n;
        unordered_set<int> hashSet;
        for(int i=1;i<=n;i++)
            hashSet.insert(i*i);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int sum=i*i+j*j;
                if(sum>bound) break;
                if(hashSet.count(sum))
                    count+=2;
            }
        }
        return count;
    }
};

int main(){

return 0;
}