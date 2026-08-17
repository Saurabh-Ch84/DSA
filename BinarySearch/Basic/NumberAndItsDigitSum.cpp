#include<bits/stdc++.h>
using namespace std;

class Solution {
    int sumOfDigits(int n){
        int sum=0;
        while(n){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
public:
    int numberCount(int n, int k) {
        // If k is greater than n, no number can satisfy the condition
        if(k > n) return 0;
        int low = 1, high = n, firstNumberInRange = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // If condition is met, mid could be the answer, but look for a smaller one on the left
            if(mid - sumOfDigits(mid) >= k){
                firstNumberInRange = mid;
                high = mid - 1; 
            }
            // If condition fails, we need a larger number, search right
            else low = mid + 1;
        }
        // If no number satisfied the condition
        if(firstNumberInRange == -1) return 0;
        // All numbers from firstNumberInRange up to n are valid
        return n - firstNumberInRange + 1;
    }
};

int main(){

return 0;
}