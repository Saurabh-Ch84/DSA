#include<bits/stdc++.h>
using namespace std;

class Solution{
    int posInf=INT_MAX, negInf=INT_MIN;
    struct Comp{
        bool operator()(const tuple<int,int,int> &a,const tuple<int,int,int> &b){
            if(get<0>(a)==get<0>(b)) return get<1>(a)>get<1>(b);
            return get<0>(a)<get<0>(b);
        }
    };
    void print(int n,vector<int> &arr){
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }
        public:
    void solve(int n,vector<pair<int,int>> &ranges){
        vector<tuple<int,int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({ranges[i].first,ranges[i].second,i});
        }
        sort(arr.begin(),arr.end(),Comp());

        vector<int> children(n,0);
        int mini=posInf;
        for(int i=n-1;i>=0;i--){
            int currEnd=get<1>(arr[i]);
            if(currEnd>=mini){
                int idx=get<2>(arr[i]);
                 
                children[idx]=1;
            }
            mini=min(mini,currEnd);
        }

        vector<int> parent(n,0);
        int maxi=negInf;
        for(int i=0;i<n;i++){
            int currEnd=get<1>(arr[i]);
            if(currEnd<=maxi){
                int idx=get<2>(arr[i]);
                
                parent[idx]=1;
            }
            maxi=max(maxi,currEnd);
        }
        print(n,children);
        cout<<"\n";
        print(n,parent);
    }
};

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> ranges(n);
    for(int i=0;i<n;i++){
        cin>>ranges[i].first>>ranges[i].second;
    }
    Solution s;
    s.solve(n,ranges);
return 0;
}