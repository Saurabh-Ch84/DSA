#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    int recursion(int i,int s,int n,int sum){
        if(i==n) return (s==sum);
        int ans=0;
        for(int d=(i? 0: 1);d<=9;d++){
            if(s+d>sum) break;
            int nextAns=recursion(i+1,s+d,n,sum);
            ans+=nextAns;
        }
        return ans;
    }
  public:
    int countWaysRecursion(int n, int sum) {
        // code here
        int ans=recursion(0,0,n,sum);
        return (ans? ans: -1);
    }
};

int main(){

return 0;
}