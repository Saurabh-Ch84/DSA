#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long count=0,prev=0;
        for(int i=0;i<n;i++){
            if(i && prev>1){
                long long curr=prev-2+1;
                count+=curr;
                prev=curr;
            }
            else{
                long long curr=1;
                for(int j=i;j<n-1;j++){
                    if(prices[j]-prices[j+1]!=1) break;
                    curr++;
                }
                count+=curr;
                prev=curr;
            }
        }
        return count;
    }
};

int main(){

return 0;
}