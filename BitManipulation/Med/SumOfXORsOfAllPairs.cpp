#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long sum=0;
        for(int bit=0;bit<31;bit++){
            int count=0;
            for(int i=0;i<n;i++){
                if((arr[i]>>bit) & 1) count++;
            }
            sum=sum+1LL*(count)*(n-count)*(1<<bit);
        }
        return sum;
    }
};

int main(){

return 0;
}