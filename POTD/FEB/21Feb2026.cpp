#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vb=vector<bool>;
using vi=vector<int>;
class Solution1 {
	void sieve(vb &prime,int n){
		prime[0]=false, prime[1]=false;
		for(int i=2;i<n;i++){
			if(!prime[i]) continue;
			for(int j=i*i;j<n;j+=i)
				prime[j]=false;
		}
	}
public:
    int countPrimeSetBits(int left, int right) {
        int n=32;
        vb prime(n,true);
        sieve(prime,n);
        int count=0;
        vi dp(right+1,0);
        for(int i=1;i<=right;i++){
        	dp[i]=1+dp[i&(i-1)];
        	if(i>=left && prime[dp[i]]) count++;
        }
        return count;
    }
};

using vi=vector<int>;
class Solution2 {
    bool check(vi &cit,int mid,int n){
       int idx=-1, low=0, high=n-1;
       while(low<=high){
           int mid_=low+(high-low)/2;
           int val=cit[mid_];
           if(val>=mid){
              idx=mid_;
              high=mid_-1;
           }
           else low=mid_+1;
       }
       if(idx==-1) return false;
       return (n-idx>=mid);
    }
  public:
    int hIndex(vector<int>& citations){
        // code here
        sort(citations.begin(),citations.end());
        int ans=-1, n=citations.size();
        int low=0, high=citations[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            bool resp=check(citations,mid,n);
            if(resp){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};

class Solution3 {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int low = 0, high = n - 1;
        int ans = 0;  // keep track of best answer so far

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int h = n - mid;  // candidate h-index

            if (citations[mid] >= h) {
                ans = h;          // update answer
                high = mid - 1;   // try to find larger h
            } else {
                low = mid + 1;    // need more citations
            } 
        }
        return ans;
    }
};


int main(){

return 0;
}