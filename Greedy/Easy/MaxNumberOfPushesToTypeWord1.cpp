#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length(), pushes=0, presses=1;
        while(n>0){
            pushes=pushes+presses*min(8,n);
            presses++;
            n=n-8;
        }
        return pushes;
    }
};

int main(){

return 0;
}