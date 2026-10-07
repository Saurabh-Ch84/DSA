#include<bits/stdc++.h>
using namespace std;

long long countSubarraysDivisibleByK(vector<int> &a,int k){
    int n=a.size();
    vector<int> freqOfMods(k,0);
    freqOfMods[0]=1;
    long long prefixSum=0;
    for(int i=0;i<n;i++){
        prefixSum+=a[i];
        prefixSum=(prefixSum%k+k)%k;
        freqOfMods[prefixSum]++;
    }
    long long ans=0;
    for(int &f: freqOfMods)
        ans=ans+1LL*(f)*(f-1)/2;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<countSubarraysDivisibleByK(a,n);
return 0;
}