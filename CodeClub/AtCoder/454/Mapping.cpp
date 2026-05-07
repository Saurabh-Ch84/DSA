#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;

class Solution{
    int m,n;
    vint arr;
        public:
    void setArr(int m,int n,vint &arr){
        this->m=m;
        this->n=n;
        this->arr=arr;
    }
    pair<bool,bool> getAns(){
        int mSum=m*(m+1)/2;
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++){
            int color=arr[i];
            if(!hashMap[color])
                mSum=mSum-color;
            hashMap[color]++;
        }
        return {hashMap.size()==n,!mSum};
    }
};

int main(){
    int t;
    cin>>t;

    Solution s;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int j=0;j<n;j++)
            cin>>arr[j];
        s.setArr(m,n,arr);
        pair<bool,bool> res=s.getAns();
        cout<<res.first<<" "<<res.second<<endl;
    }
return 0;
}