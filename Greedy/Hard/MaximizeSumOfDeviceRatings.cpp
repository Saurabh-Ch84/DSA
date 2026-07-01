#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size(), n=units[0].size();
        if(m==1) return *min_element(units[0].begin(),units[0].end());
        long long sum=0;
        if(n==1){
            for(int i=0;i<m;i++)
                sum+=units[i][0];
            return sum;
        }
        int min2ndElem=1e9+7, min2ndElemIndx=-1;
        for(int i=0;i<m;i++){
            sort(units[i].begin(),units[i].end());
            if(units[i][1]<min2ndElem){
                min2ndElemIndx=i;
                min2ndElem=units[i][1];
            }
        }
        int mini=units[min2ndElemIndx][0];
        for(int i=0;i<m;i++){
            if(i==min2ndElemIndx)
                continue;
            sum+=units[i][1];
            mini=min(mini,units[i][0]);
        }
        return sum+mini;
    }
};

int main(){

return 0;
}