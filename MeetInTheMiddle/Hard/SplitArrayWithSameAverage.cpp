#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    vvint getSubSet(vint &nums,int low,int n){
        vvint subSet(n+1);
        for(int i=0;i<(1<<n);i++){
            int k=0, sum=0;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    sum+=nums[low+j];
                    k++;
                }
            }
            subSet[k].push_back(sum);
        }
        return subSet;
    }
public:
    bool splitArraySameAverage(vint &nums) {
        int n=nums.size(), S=accumulate(nums.begin(),nums.end(),0);
        int n1=n/2, n2=n-n1;
        vvint subSetA=getSubSet(nums,0,n1);
        vvint subSetB=getSubSet(nums,n1,n2);

        for(int i=0;i<=n2;i++)
            sort(subSetB[i].begin(),subSetB[i].end());

        for(int len=1;len<=n/2;len++){
            if((S*len)%n!=0) continue;
            int sumA=(S*len)/n;
            for(int i=0;i<=min(len,n1);i++){
                int j=len-i;
                if(j>n2) continue;
                for(int &val: subSetA[i]){
                    int needed=sumA-val;
                    if(binary_search(subSetB[j].begin(),subSetB[j].end(),needed))
                        return true;
                }
            }
        }
        return false;
    }
};

int main(){

return 0;
}