#include<bits/stdc++.h>
using namespace std;

int solve(int n,string &directions){
    if(n<2) return n;
    vector<int> eastLookers(n,0);
    for(int i=n-2;i>=0;i--)
        eastLookers[i]=eastLookers[i+1]+(directions[i+1]=='E');
    int westLookers=0, mini=n;
    for(int i=0;i<n;i++){
        int peopleToChange=eastLookers[i]+westLookers;
        mini=min(mini,peopleToChange);
        if(directions[i]=='W') westLookers++;
    }
    return mini;
}

int main(){
    int n;
    string directions;
    cin>>n>>directions;
    cout<<solve(n,directions);
return 0;
}