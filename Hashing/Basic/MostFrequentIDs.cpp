#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

using vi=vector<int>;
using vll=vector<long long>;
using memo_t1=unordered_map<int,long long>;
using memo_t2=set<pair<long long,int>>;

class Solution {
public:
    vector<long long> mostFrequentIDs(vi &nums, vi &freq){
        memo_t1 hashMap;
        memo_t2 set_;
        int n=nums.size();
        vll result(n,0);
        for(int i=0;i<n;i++){
            long long f=freq[i];
            int val=nums[i];
            if(hashMap.count(val)){
                long long f_=hashMap[val];
                set_.erase({f_,val});
                f=f_+f;
            }
            if(f>0){
                hashMap[val]=f;
                set_.insert({f,val});
            }
            result[i]=(!set_.empty()? set_.rbegin()->first:0);
        }
        return result;
    }
};

int main(){

return 0;
}