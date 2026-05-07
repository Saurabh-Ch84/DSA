#include <bits/stdc++.h>

using namespace std;
using vint=vector<int>;
using vllong=vector<long long>;

class Solution{
    vint arr;
    vllong prefixSum, diff;
    int n;
        public:
    Solution(){}
    
    void setArr(vint &a){
        arr=a;
        n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=1;i<n;i++)
            diff.push_back(arr[i]-arr[i-1]);
            
        sort(diff.begin(),diff.end());
        
        prefixSum.resize(n,0);
        for(int i=0;i<diff.size();i++)
            prefixSum[i+1]=prefixSum[i]+diff[i];
    }
    
    long long findAns(int x){
        int ub=upper_bound(diff.begin(), diff.end(), x)-diff.begin();
        long long count=prefixSum[ub]+1LL*(n-ub-1)*x+x;
        return count;
    }
};

int main() {
	// your code goes here
    int n, q;
    Solution s;
    cin>>n>>q;
    vint temp(n);
    for(int i=0;i<n;i++)
        cin>>temp[i];

    s.setArr(temp);
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        cout<<s.findAns(x)<<endl;
    }
}
