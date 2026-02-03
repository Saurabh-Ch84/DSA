#include<iostream>
#include<vector>
#include<map>
#include<numeric>
#include<set>
#include<climits>
using namespace std;

// Brute force
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        if (k == 1) return nums[0];
        
        int left = 1, right = 1, needed = k - 1;
        long long mini = LLONG_MAX;
        
        map<int, int> hashMap;
        
        while (left <= n - needed) {
            while (right < n && right <= left + dist) {
                hashMap[nums[right]]++;
                right++;
            }
            long long current_cost = nums[0];
            int count = 0;
            for(auto &p: hashMap) {
                int val=p.first, freq=p.second;
                int take = min(needed - count, freq);
                current_cost += (long long)val * take;
                count += take;
                if (count == needed) break;
            }
            if(count == needed)
                mini = min(mini, current_cost);
            if(hashMap.count(nums[left]) && --hashMap[nums[left]]==0)
                    hashMap.erase(nums[left]);
            left++;
            if (right < left) right = left;
        }

        return mini;
    }
};

// optimal version
using pii=pair<int,int>;
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        set<pii> minSet, remSet;
        int n=nums.size(), left=1, right=1, needed=k-1;
        long long runningSum=0, mini=LLONG_MAX;
        while(n-left>=needed){
            while(right<n && right-left<=dist){
                minSet.insert({nums[right],right});
                runningSum+=nums[right];
                if(minSet.size()>needed){
                    auto rItr=minSet.rbegin();
                    pii out=*rItr;
                    runningSum-=out.first;
                    remSet.insert(out);
                    minSet.erase(out);
                }
                right++;
            }
            if(minSet.size()==needed)
                mini=min(mini,runningSum+nums[0]);
            
            pii out={nums[left],left};
            if(minSet.count(out)){
                minSet.erase(out);
                runningSum-=nums[left];
                if(!remSet.empty()){
                    auto itr=remSet.begin();
                    int val=itr->first;
                    runningSum+=val;
                    minSet.insert(*itr);
                    remSet.erase(itr);
                }
            }
            else remSet.erase(out);
            left++;
        }
        return mini;
    }
};

using vi=vector<int>;
using pii=pair<int,int>;
class Solution {
    pii kadaneCircular(vi &arr){
        int sum1=0,maxi=INT_MIN;
        int sum2=0,mini=INT_MAX;
        for(int &val: arr){
            sum1+=val;
            sum2+=val;
            maxi=max(maxi,sum1);
            mini=min(mini,sum2);
            if(sum1<0) sum1=0;
            if(sum2>0) sum2=0;
        }
        return {maxi,mini};
    }
  public:
    int maxCircularSum(vector<int> &arr) {
        int total=accumulate(arr.begin(),arr.end(),0);
        pii p=kadaneCircular(arr);
        int sum=p.first, circularSum=total-p.second;
        if(sum<0) return sum;
        return max(sum,circularSum);
    }
};

int main(){

return 0;
}