#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long sum=0;
        for(int bit=0;bit<31;bit++){
            int count=0;
            for(int i=0;i<n;i++){
                if(arr[i]>>bit & 1) count++;
            }
            sum=sum+1LL*count*(count-1)/2*(1<<bit);
        }
        return sum;
    }
};

int main(){

return 0;
}