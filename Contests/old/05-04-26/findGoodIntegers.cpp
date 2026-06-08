#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long,int> hashMap;
        vector<int> result;
        for(int i=1;i<1e3;i++){
            long long aCube=i*i*i;
            if(aCube>n) break;
            for(int j=i;j<1e3;j++){
                long long totalSum=aCube+j*j*j;
                if(totalSum>n) break;
                else if(totalSum<=n && ++hashMap[totalSum]==2)
                    result.push_back(totalSum);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};

int main(){

return 0;
}