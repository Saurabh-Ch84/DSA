#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long,int> hashMap;
        for(int i=1;i<1e3;i++){
            long long sum=i*i*i;
            for(int j=i;j<1e3;j++){
                if(sum+j*j*j<=n)
                    hashMap[sum+j*j*j]++;
            }
        }
        vector<int> result;
        for(auto &p: hashMap)
            if(p.second>1) result.push_back(p.first);

        sort(result.begin(),result.end());
        return result;
    }
};

int main(){

return 0;
}