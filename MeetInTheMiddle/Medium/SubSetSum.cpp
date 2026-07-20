#include<bits/stdc++.h>
using namespace std;

using vll=vector<long long>;
using vint=vector<int>;

class Solution{
    vint arr;
    vll getAllSubsetSum(int low,int n){
        vll subSetSum(1<<n,0);
        for(int m=0;m<(1<<n);m++){
            long long sum=0;
            for(int i=0;i<n;i++)
                if(m & (1<<i)) sum+=arr[low+i];
            subSetSum[m]=sum;
        }
        return subSetSum;
    }
        public:
    void set(vint a){
        arr=a;
    }
    long long numberOfSubSetsWithSumEqualToX(int x){
        int n=arr.size();
        int n1=n/2, n2=n-n1;
        vll sumSetsA=getAllSubsetSum(0,n1);
        vll sumSetsB=getAllSubsetSum(n1,n2);
        
        long long count=0;
        sort(sumSetsB.begin(),sumSetsB.end());
        for(long long &val: sumSetsA){
            long long remVal=x-val;
            int ub=upper_bound(sumSetsB.begin(),sumSetsB.end(),remVal)-sumSetsB.begin();
            int lb=lower_bound(sumSetsB.begin(),sumSetsB.end(),remVal)-sumSetsB.begin();
            int ways=ub-lb;
            count+=ways;
        }
        return count;
    }
};

int main(){
    Solution s;
    s.set({1,2,3,2,2,1,0,4,2,3});
    cout<<s.numberOfSubSetsWithSumEqualToX(5)<<endl;
return 0;
}