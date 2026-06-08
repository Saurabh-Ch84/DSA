#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vll=vector<long long>;
    using vvint=vector<vint>;
public:
    vint minCost(vint &nums,vvint &queries){
        int n=nums.size();
        vint closest(n,-1);
        closest[0]=1, closest[n-1]=n-2;
        for(int i=1;i<n-1;i++){
            int left=nums[i-1];
            int right=nums[i+1];
            if(abs(nums[i]-left)<=abs(right-nums[i]))
                closest[i]=i-1;
            else closest[i]=i+1;
        }
        vll costToMoveLeft(n,0), costToMoveRight(n,0);
        for(int i=0;i<n-1;i++){
            if(closest[i]==i+1) costToMoveRight[i]=1;
            else costToMoveRight[i]=abs(nums[i+1]-nums[i]);
        }
        for(int i=n-1;i>0;i--){
            if(closest[i]==i-1) costToMoveLeft[i]=1;
            else costToMoveLeft[i]=abs(nums[i]-nums[i-1]);
        }
        vll prefixLeft(n,0), prefixRight(n,0);
        for(int i=0;i<n-1;i++)
            prefixRight[i+1]=prefixRight[i]+costToMoveRight[i];
        for(int i=n-1;i>0;i--)
            prefixLeft[i-1]=prefixLeft[i]+costToMoveLeft[i];
        vint res;
        for(vint &q: queries){
            int l=q[0], r=q[1], cost=0;
            if(l<r) cost=prefixRight[r]-prefixRight[l];
            else cost=prefixLeft[r]-prefixLeft[l];
            res.push_back(cost);
        }
        return res;
    }
};

int main(){

return 0;
}