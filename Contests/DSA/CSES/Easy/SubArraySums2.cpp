#include<bits/stdc++.h>
using namespace std;

long long solve(int n,int x,vector<int> &a){
    map<long long,long long> hashMap={{0,1}};
    long long sum=0, count=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
        long long remSum=sum-x;
        if(hashMap.count(remSum))
            count+=hashMap[remSum];
        hashMap[sum]++;
    }
    return count;
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve(n,x,a);
return 0;
}