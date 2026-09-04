#include<bits/stdc++.h>
using namespace std;

long long negInf=-1e14;
long long solve(int n,vector<int> &arr){
    long long sum=0, maxi=negInf;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<0) sum=0;
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<solve(n,arr);
return 0;
}