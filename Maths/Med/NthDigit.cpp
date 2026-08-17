#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findNthDigit(int n) {
        long long powerOf10=10;
        int digits=1, ans=-1;
        while(n){
            int low=powerOf10/10;
            long long high=powerOf10-1;
            long long totalNumbers=high-low+1;
            long long totalDigits=totalNumbers*digits;
            
            if(n>totalDigits) {
                n-=totalDigits;
            }
            else {
                // 1. Find the exact target number
                long long num = low + (n - 1) / digits;
                // 2. Convert to string to easily extract the digit
                string s = to_string(num);
                // 3. Find the exact index within that number
                ans = s[(n - 1) % digits] - '0';
                break;
            }
            powerOf10*=10;
            digits++;
        }
        return ans;
    }
};

int main(){

return 0;
}