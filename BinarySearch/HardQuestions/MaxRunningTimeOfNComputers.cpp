#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
    bool response(vector<int> &batteries,long long mid,int n){
        long long total=n*mid, sum=0;
        for(int &battery: batteries){
            sum+=min(mid,1LL*battery);
            // sum+=battery; //This won't work because of overestimation.
            if(sum>=total) return true;
        }
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0,low=LLONG_MAX;
        for(int &battery :batteries){
            sum+=battery;
            low=min(low,1LL*battery);
        }
        long long high=sum/n,result=0;

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(response(batteries,mid,n)){
                result=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return result;
    }
};

int main(){

return 0;
}