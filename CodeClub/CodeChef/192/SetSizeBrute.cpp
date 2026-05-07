#include <bits/stdc++.h>

using namespace std;
using vint=vector<int>;

class Solution{
    vint arr;
    int n;
    int upperBound(long long low,long long high,int val){
        int ans=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid>val){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
        public:
    Solution(){}
    
    void setArr(vint &a){
        arr=a;
        n=arr.size();
        sort(arr.begin(),arr.end());
    }
    
    long long findAns1(int x){
        long long count=0, mini=0;
        for(int i=0;i<n;i++){
            long long ub;
            if(mini>=arr[i]+1)
                ub=upperBound(arr[i]+1,arr[i]+x,mini);
            else ub=arr[i]+1;
            count+=arr[i]+x-ub+1;
            mini=arr[i]+x;
        }
        return count;
    }

    long long findAns2(int x){
        long long count=0, mini=0;
        for(int i=0;i<n;i++){
            long long ub = max((long long)arr[i] + 1, mini + 1);
            count += arr[i] + x - ub + 1;
            mini = arr[i] + x;
        }
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
        cout<<s.findAns2(x)<<endl;
    }
}
