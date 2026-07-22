#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> prefixPrice(n,0);
        vector<long long> prefixProfit(n,0);
        for(int i=0;i<n;i++){
            prefixPrice[i]=1LL*prices[i]+(i ? prefixPrice[i-1] : 0);
            prefixProfit[i]=1LL*prices[i]*strategy[i]+(i ? prefixProfit[i-1] : 0);
        }
        long long original=prefixProfit[n-1];
        long long maxi=original;
        for(int i=0;i<n-k+1;i++){
            long long x=prefixProfit[i+k-1]-(i? prefixProfit[i-1] : 0);
            long long y=prefixPrice[i+k-1]-prefixPrice[i+k/2-1];
            long long modified=original-x+y;
            maxi=max(maxi,modified);
        }
        return maxi;
    }
};

int main(){

return 0;
}