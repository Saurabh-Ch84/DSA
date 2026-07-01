#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuilding(int n,vector<vector<int>> &restrictions) {
        if(restrictions.empty()) return n-1;

        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});

        sort(restrictions.begin(),restrictions.end());
        int maxi=0, m=restrictions.size();

        for(int i=1;i<m;i++){
            int height=min(restrictions[i][0]-restrictions[i-1][0]+restrictions[i-1][1], restrictions[i][1]);
            restrictions[i][1]=height;
        }
        for(int i=m-2;i>=0;i--){
            int height=min(restrictions[i+1][0]-restrictions[i][0]+restrictions[i+1][1], restrictions[i][1]);
            restrictions[i][1]=height;
        }
        for(int i=1;i<m;i++){
            int height=max(restrictions[i-1][1],restrictions[i][1])+(restrictions[i][0]-restrictions[i-1][0]-abs(restrictions[i-1][1]-restrictions[i][1]))/2;
            maxi=max(maxi,height);
        }
        return maxi;
    }
};

int main(){

return 0;
}