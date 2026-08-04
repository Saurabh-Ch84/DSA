#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int binarySearch(vvint &arr,int low,int high,int x){
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid][0]>=x){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
public:
    vint findRightInterval(vvint &intervals) {
        vvint arr;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int l=intervals[i][0], r=intervals[i][1];
            arr.push_back({l,r,i});
        }
        
        sort(arr.begin(),arr.end());
        vint res(n,-1);
        for(int i=0;i<n;i++){
            int startI=arr[i][0], endI=arr[i][1], I=arr[i][2];
            if(startI==endI){
                res[I]=I;
                continue;
            }
            int idx=binarySearch(arr,i+1,n-1,endI);
            if(idx!=-1){
                int ansI=arr[idx][2];
                res[I]=ansI;
            }
        }
        return res;
    }
};

int main(){

return 0;
}