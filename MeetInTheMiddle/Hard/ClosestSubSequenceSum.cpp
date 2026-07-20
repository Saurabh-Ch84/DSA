#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vlong=vector<long>;
    using vint=vector<int>;
    vlong getSubSetSum(int low,int n,vint &nums){
        vlong array(1<<n,0);
        for(int mask=0;mask<(1<<n);mask++){
            long sum=0;
            for(int i=0;i<n;i++)
                if(mask & (1<<i)) sum+=nums[low+i];
            array[mask]=sum;
        }
        return array;
    }
    long customBinarySearch(long x,int goal,vlong &subSetSumB){
        int low=0, high=subSetSumB.size()-1;
        long diff=1e10;
        while(low<=high){
            int mid=low+(high-low)/2;
            long sum=1L*x+subSetSumB[mid];
            diff=min(diff,abs(sum-goal));
            if(!diff) break;
            if(sum<goal) low=mid+1;
            else high=mid-1;
        }
        return diff;
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int n1=n/2, n2=n-n1;
        vlong subSetSumA=getSubSetSum(0,n1,nums);
        vlong subSetSumB=getSubSetSum(n1,n2,nums);

        long mini=1e10;
        sort(subSetSumB.begin(),subSetSumB.end());
        for(long &sumA: subSetSumA){
            long ans=customBinarySearch(sumA,goal,subSetSumB);
            mini=min(mini,ans);
            if(!mini) break;
        }
        return mini;
    }
};


int main(){

return 0;
}