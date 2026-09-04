#include<bits/stdc++.h>
using namespace std;

int solve(int n,int x,vector<int> &weight){
    sort(weight.begin(),weight.end());
    int left=0, right=n-1, count=0;
    while(left<=right){
        if(left!=right && weight[left]+weight[right]<=x)
            left++;
        right--;
        count++;
    }
    return count;
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> weight(n);
    for(int i=0;i<n;i++)
        cin>>weight[i];
    cout<<solve(n,x,weight);
return 0;
}