#include<bits/stdc++.h>
using namespace std;

void solve(int x,int n,vector<int> &p){
    set<int> lights={0,x};
    multiset<int> gaps={x};

    for(int i=0;i<n;i++){
        auto nextItr=lights.lower_bound(p[i]);
        auto prevItr=nextItr;
        prevItr--;
        int oldGap=*nextItr-*prevItr;
        auto delItr=gaps.find(oldGap);
        gaps.erase(delItr);
        int newGapLeft=p[i]-*prevItr, newGapRight=*nextItr-p[i];
        lights.insert(p[i]);
        gaps.insert(newGapLeft);
        gaps.insert(newGapRight);
        cout<<*gaps.rbegin()<<" ";
    }
}

int main(){
    int x,n;
    cin>>x>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++)
        cin>>p[i];
    solve(x,n,p);
return 0;
}