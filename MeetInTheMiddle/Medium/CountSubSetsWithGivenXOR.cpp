#include<bits/stdc++.h>
using namespace std;

/*  
     Constraints:
    1 ≤ arr.size() ≤ 20
    1 ≤ k ≤ 100
    0 ≤ arr[i]  ≤ 100
*/

class Solution1 {
    // meet in the middle approach
    using vint=vector<int>;
    vint getSubSet(vint &arr,int low,int n){
        vint subSet(1<<n,0);
        for(int mask=0; mask<(1<<n); mask++){
            int xorSubSet=0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)) 
                    xorSubSet=xorSubSet^arr[low+i];
            }
            subSet[mask]=xorSubSet;
        }
        return subSet;
    }
  public:
    int subsetXOR(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int n1=n/2, n2=n-n1;
        vint subSetA=getSubSet(arr,0,n1);
        vint subSetB=getSubSet(arr,n1,n2);
        sort(subSetB.begin(),subSetB.end());
        int count=0;
        for(int &leftXOR: subSetA){
            int remXOR=k^leftXOR;
            int temp=upper_bound(subSetB.begin(),subSetB.end(),remXOR) 
                     -lower_bound(subSetB.begin(),subSetB.end(),remXOR);
            count=count+max(0,temp);
        }
        return count;
    }
};

class Solution2 {
    // memoization approach
    using vint=vector<int>;
    using vvint=vector<vint>;
    int getBound(int x){
        int n=1;
        while(n<=x) n=n<<1;
        return n;
    }
    int recursion(int i,int j,int n,int k,vint &arr,vvint &dp){
        if(i==n) return (j==k);
        if(dp[i][j]!=-1) return dp[i][j];
        int skip=recursion(i+1,j,n,k,arr,dp);
        int take=recursion(i+1,j^arr[i],n,k,arr,dp);
        return dp[i][j]=skip+take;
    }
  public:
    int subsetXOR(vector<int> &arr, int k) {
        // code here
        int n=arr.size(), bound=getBound(*max_element(arr.begin(),arr.end()));
        vvint dp(n,vint(bound,-1));
        return recursion(0,0,n,k,arr,dp);
    }
};

class Solution3 {
    // XOR basis approach
    using vint=vector<int>;
    int getXORBasis(vint &arr,vint &xorBasis){
        int basisSize=0;
        for(int &x: arr){
            int num=x;
            for(int i=31;i>=0;i--){
                if((num & (1<<i))==0) 
                    continue;
                if(!xorBasis[i]){
                    xorBasis[i]=num;
                    basisSize++;
                    break;
                }
                else num=num^xorBasis[i];
            }
        }
        return basisSize;
    }
    bool canFormK(int k,vint &xorBasis){
        int num=k;
        for(int i=31;i>=0;i--){
            if((num & (1<<i))==0) 
                continue;
            if(!xorBasis[i])
                return false;
            else num=num^xorBasis[i];
        }
        return (num==0);
    }
  public:
    int subsetXOR(vector<int> &arr, int k) {
        // code here
        vint xorBasis(32,0);
        int basisSize=getXORBasis(arr,xorBasis);
        if(!canFormK(k,xorBasis)) return 0;
        int n=arr.size();
        return 1<<(n-basisSize);
    }
};

int main(){

return 0;
}