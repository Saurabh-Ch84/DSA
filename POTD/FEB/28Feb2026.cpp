#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution1 {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n=arr1.size(), m=arr2.size(), mini=INT_MAX;
        vector<int> ans={-1,-1};
        int left=0, right=m-1;
        while(left<n && right>=0){
            int sum=arr1[left]+arr2[right];
            int d=abs(sum-x);
            if(d<mini){
                mini=d;
                ans[0]=arr1[left], ans[1]=arr2[right];
                if(!mini) return ans;
            }
            if(sum<x) left++;
            else right--;
        }
        return ans;
    }
};

// Brute-Force
class Solution2 {
    void decToBinary(string &num, int x){
        while(x){
            num.push_back((x % 2) + '0');
            x /= 2;
        }
    }
public:
    int concatenatedBinary(int n) {
        string num;
        for(int i = n; i > 0; i--)
            decToBinary(num, i);
        
        long long ans = 0;
        const long long mod = 1e9 + 7;
        while(!num.empty()){
            int bit = num.back() - '0';
            num.pop_back();
            ans = ((ans << 1) | bit) % mod;
        }
        return (int)ans;
    }
};

class Solution3 {
    void decToBinary(string &num, int x){
        while(x){
            int rem=x%2;
            num.push_back(rem+'0');
            x=x/2;
        }
    }
public:
    int concatenatedBinary(int n) {
        string num;
        // reverse order
        for(int i=n;i>0;i--)
            decToBinary(num, i);
        
        long long ans=0;
        int mod=1e9+7;
        // MSB First then LSB
        while(!num.empty()){
            int bit=num.back()-'0';
            num.pop_back();
            ans=ans|bit;
            ans=ans%mod;
            if(!num.empty()) 
                ans=ans<<1;
        }
        return (int)ans;
    }
};

// Better
class Solution4 {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        const long long mod = 1e9 + 7;

        for(int i = 1; i<=n; i++){
            int shift=0, x=i;
            while(x){
                shift++;
                x=x/2;
            }
            ans=((ans<<shift)|i)%mod;
        }   
        return (int)ans;
    }
};

//Optimal
class Solution5 {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        const long long mod = 1e9 + 7;
        int shift=0;
        for(int i = 1; i<=n; i++){
            if((i & (i-1))==0) shift++;
            ans=((ans<<shift)|i)%mod;
        }   
        return (int)ans;
    }
};

int main(){

return 0;
}