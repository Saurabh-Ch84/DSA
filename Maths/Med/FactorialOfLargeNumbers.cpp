#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// User function template for C++

class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        vector<int> fact={1};
        for(int x=2;x<=n;x++){
            int m=fact.size(),carry=0;
            for (int i = 0; i < m; i++) {
                int val = fact[i] * x + carry;
                fact[i] = val % 10;
                carry = val / 10;
            }
            while (carry){
                fact.push_back(carry % 10);
                carry/=10;
            }
        }
        reverse(fact.begin(),fact.end());
        return fact;
    }
};

int main(){

return 0;
}