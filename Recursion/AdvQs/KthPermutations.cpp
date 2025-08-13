#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        // Prepare the list of numbers and compute n!
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            fact *= i;
        }
        k--; // Convert to 0-based index
        string result;
        for (int i = n; i >= 1; i--) {
            fact /= i;
            int index = k / fact;
            k %= fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
        }
        return result;
    }
};


int main(){

return 0;
}