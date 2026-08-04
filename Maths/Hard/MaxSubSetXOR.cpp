#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    vint getGaussianElimination(vint &arr){
        vint xorBasis(32,0);
        for(int &x: arr){
            int num=x;
            for(int bit=31;bit>=0;bit--){
                if((num & (1<<bit))==0) 
                    continue;
                if(!xorBasis[bit]){
                    xorBasis[bit]=num; 
                    break;
                }
                else num=num^xorBasis[bit];
            }
        }
        return xorBasis;
    }
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        vint xorBasis=getGaussianElimination(arr);
        int ans=0;
        for(int bit=31;bit>=0;bit--){
            int num=xorBasis[bit];
            if((ans^num)>ans)
                ans=ans^num; 
        }
        return ans;
    }
};

int main(){

return 0;
}