#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vbool=vector<bool>;
    using vint=vector<int>;
    using vvint=vector<vint>;
    bool hasAnyValley(int l,int r,vint &valleysArray){
        int low=0, high=valleysArray.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valleysArray[mid]>l && valleysArray[mid]<r)
                return true;
            if(valleysArray[mid]>=r) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
  public:
    vbool processQueries(vint &arr,vvint &queries) {
        // code here
        int n=arr.size(), m=queries.size();
        vint valleysArray;
        for(int i=1;i<n-1;i++){
            if(arr[i-1]>arr[i] && arr[i]<arr[i+1])
                valleysArray.push_back(i);
        }
        vbool res(m,0);
        for(int i=0;i<m;i++){
            int l=queries[i][0], r=queries[i][1];
            // range is too small or it contains no valleys then it's guaranteed to have atleast 1 peak or
            // non-decreasing or non-increasing.
            if(r-l+1<=2 || !hasAnyValley(l,r,valleysArray)) 
                res[i]=1;
        }
        return res;
    }
};

int main(){

return 0;
}