#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Data{
        public:
    long ub,lb,nums;
    Data(long ub_=0,long lb_=0,long nums_=0){
        ub=ub_;
        lb=lb_;
        nums=nums_;
    }
};

class Solution {
    void precompute(vector<Data> &arr){
        for(int k=1;k<=16;k++){
            long ub=pow(4,k)-1,lb=pow(4,k-1);
            long nums=ub-lb+1;
            arr[k]=Data(ub,lb,nums);
        }
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<Data> arr(17);
        precompute(arr);
        long long ans=0;
        for(vector<int> &query:queries){
            long count=0;
            long long totalCount=0;
            int l=query[0],r=query[1];
            for(int k=1;k<=16;k++){
                if(arr[k].lb > r) break;
                if(arr[k].ub < l) continue;
                long lb=max(arr[k].lb,(long)l);
                long ub=min(arr[k].ub,(long)r);
                long count=ub-lb+1;
                totalCount+=count*k*1LL;
            }
            ans+=(totalCount+1)/2;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> queries={{2,7}};
    cout<<s.minOperations(queries);
return 0;
}