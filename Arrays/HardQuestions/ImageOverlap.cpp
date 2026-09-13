#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size(), maxi=0;
        for(int rowOffset=-(n-1);rowOffset<=n-1;rowOffset++){
            for(int colOffset=-(n-1);colOffset<=n-1;colOffset++){
                int count=0;
                for(int i=0;i<n;i++){
                    int i_=i+rowOffset;
                    if(i_<0 || i_>=n) continue;
                    for(int j=0;j<n;j++){
                        int j_=j+colOffset;
                        if(j_<0 || j_>=n) continue;
                        if(img1[i][j] && img2[i_][j_])
                            count++;
                    }
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}