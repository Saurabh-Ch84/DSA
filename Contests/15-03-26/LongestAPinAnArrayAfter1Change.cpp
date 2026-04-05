#include<iostream>
#include<vector>
using namespace std;

using vint=vector<int>;
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size(), maxi=2;
        vint left(n,2), right(n,2);

        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                left[i]=1+left[i-1];
                maxi=max(maxi,left[i]);
            }
        }

        for(int i=n-3;i>=0;i--){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]){
                right[i]=1+right[i+1];
                maxi=max(maxi,right[i]);
            }
        }

        for(int i=0;i<n;i++){
            if(i>0) maxi=max(maxi,left[i-1]+1);
            if(i<n-1) maxi=max(maxi,right[i+1]+1);
            if(i>0 && i<n-1){
                int dTimes2=nums[i+1]-nums[i-1];
                if(dTimes2%2==0){
                    int d=dTimes2/2, l=1, r=1;
                    if(i>1 && nums[i-1]-nums[i-2]==d)
                        l=left[i-1];
                    if(i<n-2 && nums[i+2]-nums[i+1]==d)
                        r=right[i+1];
                    maxi=max(maxi,l+r+1);
                }
            }
        }

        return maxi;
    }
};

int main(){

return 0;
}