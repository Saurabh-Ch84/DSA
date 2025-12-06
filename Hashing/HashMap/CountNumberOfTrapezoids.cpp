#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    long long nC2(int n){
        return (1LL*n*(n-1))/2;
    }
public:
    // Brute Force
    int countTrapezoidsBrute(vector<vector<int>>& points) {
        const int MOD=1e9+7;
        unordered_map<int,int> hashMap;
        for(vector<int> &point: points){
            int y=point[1];
            hashMap[y]++;
        }

        long long ans=0;
        for(auto itrI=hashMap.begin();itrI!=hashMap.end();itrI++){
            int count=itrI->second;
            if(count<2) continue;
            auto itrJ=itrI;
            itrJ++;
            long long subAns=0;
            while(itrJ!=hashMap.end()){
                int count_=(itrJ++)->second;
                if(count_<2) continue;
                subAns=subAns+(nC2(count)%MOD*nC2(count_)%MOD)%MOD;
            }
            ans=(ans+subAns)%MOD;
        }
        return (int)ans;
    }
};

int main(){

return 0;
}