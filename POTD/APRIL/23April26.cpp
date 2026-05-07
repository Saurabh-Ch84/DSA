#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;

class Solution {
    using vll=vector<long long>;
    using vint=vector<int>;
    using entry=pair<int,long long>;
    using ven=vector<entry>;
    using memo_t1=unordered_map<int,ven>;
    using memo_t0=unordered_map<int,int>;
public:
    vector<long long> distance(vector<int>& nums) {
        vll arr;
        memo_t1 memo1;
        memo_t0 memo0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            memo1[nums[i]].push_back({i,0});
            memo0[nums[i]]=0;
        }
    
        for(int i=0;i<n;i++){
            if(memo1[nums[i]].size()==1)
                arr.push_back(0);
            else{
                ven &indices=memo1[nums[i]];
                int idx=memo0[nums[i]]++, m=indices.size();
                for(int j=idx+1;j<m;j++){
                    long long dist=abs(indices[idx].first-indices[j].first);
                    indices[idx].second+=dist;
                    indices[j].second+=dist;
                }
                arr.push_back(indices[idx].second);
            }
        }
        return arr;
    }
};

class Solution {
    using vint=vector<int>;
    using ll=long long;
    using vll=vector<ll>;
    using pintvll=pair<int,vll>;
    using memo_t=unordered_map<int,pintvll>;
public:
    vll distance(vint &nums) {
        int n=nums.size();
        memo_t memo;

        for(int i=0;i<n;i++){
            if(memo.count(nums[i])){
                ll last=memo[nums[i]].second.back();
                memo[nums[i]].second.push_back(i+last);
            }
            else memo[nums[i]]={0,{i}};
        }

        vll arr;
        for(int i=0;i<n;i++){
            if(memo[nums[i]].second.size()==1)
                arr.push_back(0);
            else{
                vll &indices=memo[nums[i]].second;
                int idx=memo[nums[i]].first++, m=indices.size();
                ll leftSum=(1LL*idx*i)-(idx? indices[idx-1]: 0);
                ll rightSum=(indices[m-1]-indices[idx])-(1LL*(m-1-idx)*i);
                arr.push_back(leftSum+rightSum);
            }
        }
        return arr;
    }
};

class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        long long totalSum=accumulate(arr.begin(),arr.end(),0);
        if(totalSum & 1) return false;
        long long sum=0;
        for(int &e: arr){
            if(sum==totalSum-sum)
                return true;
            sum+=e;
        }
        return false;
    }
};

int main(){

return 0;
}
