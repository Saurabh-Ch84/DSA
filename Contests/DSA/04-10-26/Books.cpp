#include<bits/stdc++.h>
using namespace std;

int maxBooksThatCanBeRead(vector<int> &books,int n,int t){
    int sum=0, left=0, right=0, maxi=0;
    while(right<n){
        sum+=books[right];
        while(sum>t && left<=right){
            sum-=books[left];
            left++;
        }
        maxi=max(maxi,right-left+1);
        right++;
    }
    return maxi;
}

int main(){
    int n, t;
    cin>>n>>t;
    vector<int> books(n);
    for(int i=0;i<n;i++)
        cin>>books[i];
    cout<<maxBooksThatCanBeRead(books,n,t);
    return 0;
}