#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int gcd(int a,int b){
        while(b){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),gTotal=0,ones=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) ones++;
            gTotal=gcd(nums[i],gTotal);
        }

        if(gTotal>1) return -1;
        if(ones) return n-ones;
        int minLen=n;

        for(int i=0;i<n;i++){
            int g=0;
            for(int j=i;j<n;j++){
                g=gcd(g,nums[j]);
                if(g==1){
                    minLen=min(minLen,j-i+1);
                    break;
                }
            }
        }
        
        int ans=(minLen-1)+(n-1);
        return ans;
    }
};

int main(){

return 0;
}