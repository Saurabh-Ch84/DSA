#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n=s.length();
        for(int i=0;i<=n/2;i++){
            if(s[i]==s[n-i-1])
                return i;
        }
        return -1;
    }
};

int main(){

return 0;
}