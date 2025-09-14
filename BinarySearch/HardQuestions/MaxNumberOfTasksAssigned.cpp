#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(vector<int>& tasks, vector<int>& workers,int pills,int strength,int mid){

        multiset<int> hashMultiSet(workers.begin(),workers.begin()+mid);

        for(int i=mid-1;i>=0;i--){
            int req=tasks[i];
            auto itrStrong= --hashMultiSet.end();
            if(*itrStrong >= req)
                hashMultiSet.erase(itrStrong);
            else if(pills>0){
                auto itrWeak=hashMultiSet.lower_bound(req-strength);
                if(itrWeak == hashMultiSet.end())
                    return false;
                hashMultiSet.erase(itrWeak);
                pills--;
            }
            else return false;
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size(),m=workers.size();
        int low=0,high=min(n,m);

        sort(tasks.begin(),tasks.end());
        sort(workers.rbegin(),workers.rend());

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(tasks,workers,pills,strength,mid)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> tasks={8,3,12,9,10,14};
    vector<int> workers={1,9,12,4,3,5};
    int pills=3,strength=2;

    cout<<s.maxTaskAssign(tasks,workers,pills,strength);
return 0;
}