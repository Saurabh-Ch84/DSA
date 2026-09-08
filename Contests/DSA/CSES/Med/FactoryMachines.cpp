#include<bits/stdc++.h>
using namespace std;

bool check(long long mid,int n,int t,vector<int> &k){
    long long count=0;
    for(int i=0;i<n;i++){
        count=count+(mid/k[i]);
        if(count>=t) return 1;
    }
    return 0;
}

long long solve(int n,int t,vector<int> &k){
    long long low=1, high=1LL*(*max_element(k.begin(),k.end()))*t, ans=high;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(check(mid,n,t,k)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> k(n);
    for(int i=0;i<n;i++)
        cin>>k[i];
    cout<<solve(n,t,k);
return 0;
}