#include<iostream>
#include<vector>
#include<climits>

using namespace std;
using vi = vector<int> ;
using vll = vector<long long> ;
using ll= long long;

class Solution {
    bool check(ll mid,vll &diffArr,int n,int r,int k){
        vll tempDiffArr=diffArr;
        ll cumSum=0;
        for(int i=0;i<n;i++){
            cumSum+=tempDiffArr[i];
            if(cumSum<mid){
                ll need=mid-cumSum;
                if(need>k) return false;
                k-=need;
                cumSum+=need;
                if(i+2*r+1 < n) tempDiffArr[i+2*r+1] -= need;
            }
        }
        return true;
    }
    ll binarySearch(ll low,ll high,int r,int n,int k,vll &diffArr){
        ll ans=low;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(check(mid,diffArr,n,r,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
public:
    long long maxPower(vi &stations, int r, int k) {
        int n=stations.size();
        ll high=k, low=LONG_LONG_MAX;
        vll diffArr(n,0);
        for(int i=0;i<n;i++){
            int station=stations[i];
            diffArr[max(0,i-r)] += station;
            if(i+r+1<n) diffArr[i+r+1] -=station;
            low=min(low,(ll)station);
            high+=station;
        }
        return binarySearch(low,high,r,n,k,diffArr);
    }
};

int main(){

return 0;
}