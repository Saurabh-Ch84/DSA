#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &k){
    vector<int> helperArray; 
    for(int i=0;i<n;i++){
        if(helperArray.empty() || helperArray.back()<=k[i]) 
            helperArray.push_back(k[i]); 
        else{
            auto itr=upper_bound(helperArray.begin(),helperArray.end(),k[i]); 
            *itr=k[i];
        }
    }
    return helperArray.size(); 
}

int main(){
    int n;
    cin>>n;
    vector<int> k(n);
    for(int i=0;i<n;i++)
        cin>>k[i];
    cout<<solve(n,k);
return 0;
}