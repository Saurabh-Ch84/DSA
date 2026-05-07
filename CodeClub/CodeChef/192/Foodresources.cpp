#include <bits/stdc++.h>
using namespace std;
using vint=vector<int>;

class Solution{
    bool check(int mid,int m,vint &foods){
        for(int &food: foods){
            if(food>=mid){
                int m_=food/mid;
                m=m-m_;
            }
            if(m<=0) return true;
        }
        return false;
    }
        public:
    int maxDays(int n,int m,vint &foods){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=foods[i];
        
        int low=1, high=sum/m, ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,m,foods)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};

int main() {
	// your code goes here
    int n,m;
    cin>>n>>m;
    vint temp(n,-1);
    for(int i=0;i<n;i++)
        cin>>temp[i];
    
    Solution s;
    cout<<s.maxDays(n,m,temp);
}
