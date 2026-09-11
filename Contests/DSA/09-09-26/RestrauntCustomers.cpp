#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<vector<int>> &timings){
    map<int,int> eventMap;
    for(int i=0;i<n;i++){
        int arrival=timings[i][0], departure=timings[i][1];
        eventMap[arrival]++;
        eventMap[departure]--;
    }
    int maxi=0, currCustomers=0;
    for(auto &p: eventMap){
        currCustomers=currCustomers+p.second;
        maxi=max(maxi,currCustomers);
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> timings(n,vector<int>(2,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>timings[i][j];
        }
    }
    cout<<solve(n,timings);
return 0;
}