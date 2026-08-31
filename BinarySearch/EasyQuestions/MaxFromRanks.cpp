#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
  public:
    vint getMarks(vint &l,vint &r,vint &rank) {
        // code here
        int n=l.size();
        vint prefixSz(n);
        prefixSz[0]=r[0]-l[0]+1;
        for(int i=1;i<n;i++)
            prefixSz[i]=prefixSz[i-1]+(r[i]-l[i]+1);
        int m=rank.size();
        vint res(m,-1);
        for(int i=0;i<m;i++){
            int x=rank[i];
            int j=lower_bound(prefixSz.begin(),prefixSz.end(),x)-prefixSz.begin();
            int offset=(prefixSz[j]-x);
            int size=prefixSz[j]-(j? prefixSz[j-1]:0);
            res[i]=l[j]+(size-offset-1);
        }
        return res;
    }
};

int main(){

return 0;
}