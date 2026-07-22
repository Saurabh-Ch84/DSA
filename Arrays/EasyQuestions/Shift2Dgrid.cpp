#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    vvint shiftGrid(vvint &grid, int k) {
        int m=grid.size(), n=grid[0].size();
        vvint ans(m,vint(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int i_=(i+(j+k)/n)%m;
                int j_=(j+k)%n;
                ans[i_][j_]=grid[i][j];
            }
        }
        return ans;
    }
};

int main(){

return 0;
}