#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(int n,int p){
        if(1LL*(n+1)*(2*n+1)>6LL*p) return false;
        return (1LL*(n)*(n+1)*(2*n+1)<=6LL*p);
    }
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int low=1, high=3*1e8, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,p)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};


int main(){

return 0;
}