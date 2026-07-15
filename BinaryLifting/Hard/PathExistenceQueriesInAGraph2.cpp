#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int binarySearch(vvint &arr,int x,int n,int low,int high){
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid][0]>x){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    void fillUp(int n,int m,vvint &up,vvint &arr,int maxDiff){
        for(int i=0;i<n;i++){
            int uVal=arr[i][0];
            int vIndx=binarySearch(arr,uVal+maxDiff,n,i,n-1)-1;
            // upper Bound.
            up[i][0]=vIndx;
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                if(up[i][j-1]!=-1) 
                    up[i][j]=up[up[i][j-1]][j-1];
            }
        }
    }
    int getAns(int u,int v,int m,vvint &up){
        int curr=u, jumps=0;
        for(int j=m-1;j>=0;j--){
            if(up[curr][j]<v){
                curr=up[curr][j];
                jumps+=(1<<j);
            }
        }
        if(up[curr][0]>=v) return jumps+1;
        return -1;
    }
public:
    vint pathExistenceQueries(int n,vint &nums,int maxDiff,vvint &queries) {
        vvint arr(n,vint(2));
        for(int i=0;i<n;i++){
            arr[i]={nums[i],i};
        }
        sort(arr.begin(),arr.end());
        vint mapping(n,-1);
        for(int i=0;i<n;i++)
            mapping[arr[i][1]]=i;
        
        int m=log2(n)+1;
        vvint up(n,vint(m,-1));
        fillUp(n,m,up,arr,maxDiff);

        int k=queries.size();
        vint res(k,0);
        for(int i=0;i<k;i++){
            int u=mapping[queries[i][0]], v=mapping[queries[i][1]];
            if(u==v) continue;
            if(u>v) swap(u,v);
            res[i]=getAns(u,v,m,up);
        }
        return res;
    }
};

int main(){

return 0;
}