#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> arr;
    vector<long long> prefixSum;
    int n;
    int binarySearch(int x){
        int low=0, high=n-1, ansIdx=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                high=mid-1;
                ansIdx=mid;
            }
            else low=mid+1;
        }
        return ansIdx;
    }
    int customBinarySearch(int index,int k){
        int low=0, high=index-1, ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int predatorSnakes=index-mid, preySnakes=mid;
            long long totalPreyNeeded=1LL*predatorSnakes*k-(prefixSum[index-1]-(mid? prefixSum[mid-1]:0));
            if(preySnakes>=totalPreyNeeded){
                ans=predatorSnakes;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
        public:
    void setArr(vector<int> &L){
        arr=L;
        sort(arr.begin(),arr.end());
        n=arr.size();

        prefixSum.resize(n,0);
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++)
            prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    int getAns(int k){
        int index=binarySearch(k);
        int snakesAlreadyGreaterThanK=n-index;
        int snakesSmallerThanK=customBinarySearch(index,k);
        return snakesAlreadyGreaterThanK+snakesSmallerThanK;
    }
};

int main(){
    int t;
    cin>>t;
    Solution s;
    for(int i=0;i<t;i++){
        int n,q;
        cin>>n>>q;
        vector<int> L(n);
        for(int j=0;j<n;j++)
            cin>>L[j];
        s.setArr(L);
        for(int j=0;j<q;j++){
            int k;
            cin>>k; 
            cout<<s.getAns(k)<<"\n";
        }
    }
    return 0;
}