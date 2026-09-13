#include <bits/stdc++.h>
using namespace std;

int solve(int m,int n,vector<int> &D,vector<int> &P){
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        arr[i].first=D[i];
        arr[i].second=P[i];
    }
    sort(arr.begin(),arr.end());
    int left=0, right=0, mini=1e9, currPieces=0;
    while(right<n){
        currPieces+=arr[right].second;
        while(currPieces>=m && left<=right){
            int diff=arr[right].first-arr[left].first;
            mini=min(mini,diff);
            currPieces-=arr[left].second;
            left++;
        }
        right++;
        if(mini==0) break;
    }
    return mini;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n;
        cin>>m>>n;
        vector<int> D(n),P(n);
        for(int i=0;i<n;i++){
            cin>>D[i];
            cin>>P[i];
        }
        cout<<solve(m,n,D,P)<<endl;
    }
    return 0;
}
