#include<bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    vector<int> largestSubSetWithXOR_N(int n) {
        // code here
        vector<int> ans(n);
        int xorTotal=0;
        for(int i=0;i<n;i++){
            ans[i]=i+1;
            xorTotal=xorTotal^ans[i];
        }
        //no-removal
        if(xorTotal==n) return ans;
        //one-removal
        int numToDel=xorTotal^n;
        ans.erase(ans.begin()+(numToDel-1));
        return ans;
    }
};

class Solution2 {
public:
    vector<int> largestSubSetWithXOR_N(int n) {
        // TODO: write your code here
        int xor_ = 0;
        for(int i = 1; i <= n; i++) {
            xor_ ^= i;
        }
        vector<int> ans;
        int missing = -1;
        if(xor_ != n) {
            missing = (n ^ xor_);
        }
        for(int i = 1; i <= n; i++) {
            if(i != missing) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution3 {
    using vint=vector<int>;
  public:
    vector<int> largestSubSetWithXOR_N(int n) {
        // code here
        vint consecutiveNumsXOR={n,1,n+1,0}; // xor is cyclic with period 4.
        int nXOR=consecutiveNumsXOR[n%4]; // find total xor of 1 to n
        int toRemove=(nXOR^n); // find the number to remove to make the xor equal to n
        vint ans;
        for(int i=1;i<=n;i++){
            if(i!=toRemove) 
                ans.push_back(i);
        }
        return ans;
    }
};

int main(){

return 0;
}