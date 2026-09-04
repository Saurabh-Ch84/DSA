#include<bits/stdc++.h>
using namespace std;

void solve(int n,int m,vector<int> tickets,vector<int> customers){
    map<int,vector<int>> hashMap;
    for(int i=0;i<n;i++){
        // -ve because to avail lower_bound.
        hashMap[-tickets[i]].push_back(i);
    }
    for(int i=0;i<m;i++){
        int negMaxPrice=-customers[i];
        auto itr=hashMap.lower_bound(negMaxPrice);
        if(itr==hashMap.end())
            cout<<-1<<endl;
        else{
            vector<int> &tickets=itr->second;
            cout<<(-itr->first)<<endl;
            tickets.pop_back();
            if(tickets.empty()) hashMap.erase(itr);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> tickets(n), customers(m);
    for(int i=0;i<n;i++)
        cin>>tickets[i];
    for(int i=0;i<m;i++)
        cin>>customers[i];
    solve(n,m,tickets,customers);
return 0;
}