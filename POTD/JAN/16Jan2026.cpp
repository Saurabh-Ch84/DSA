#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n=arr.size();
        vvi intervals;
        for(int i=0;i<n;i++){
            if(arr[i]==-1) continue;
            int lb=max(0,i-arr[i]);
            int ub=min(n-1,i+arr[i]);
            intervals.push_back({lb,ub});
        }
        if(intervals.empty()) return -1;
        sort(intervals.begin(),intervals.end());
        
        int workHour=0, count=0, ptr=0, m=intervals.size();
        while(workHour<n){
            int maxReach=-1;
            while(ptr<m && intervals[ptr][0]<=workHour){
                maxReach=max(maxReach,intervals[ptr][1]);
                ptr++;
            }
            if(maxReach<workHour) return -1;
            workHour=maxReach+1;
            count++;
        }
        return count;
    }
};

using vi = vector<int> ;

class Solution {
  public:
    int minMen(vector<int>& arr) {
        // code here
        int n=arr.size();
        vi intervals(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i]==-1) continue;
            int lb=max(0,i-arr[i]);
            int ub=min(n-1,i+arr[i]);
            intervals[lb]=max(intervals[lb],ub);
        }
        
        int workHour=0, count=0, ptr=0;
        while(workHour<n){
            int maxReach=-1;
            while(ptr<=workHour){
                maxReach=max(maxReach,intervals[ptr]);
                ptr++;
            }
            if(maxReach<workHour) return -1;
            workHour=maxReach+1;
            count++;
        }
        return count;
    }
};

using vi = vector<int> ;
class Solution{
    const int MOD=1e9+7;
    void processPossibleSides(vi &fences,unordered_set<int> &hashSet){
        int n=fences.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int side=abs(fences[i]-fences[j]);
                hashSet.insert(side);
            }
        }
    }
public:
    int maximizeSquareArea(int m, int n,vi &hFences,vi &vFences) {
        unordered_set<int> horizontal, vertical;
        hFences.insert(hFences.end(),{1,m});
        vFences.insert(vFences.end(),{1,n});

        processPossibleSides(hFences,horizontal);
        processPossibleSides(vFences,vertical);

        long long area=-1;
        for(const int &side: horizontal){
            if(vertical.count(side)){
                area=max(area,1LL*side*side);
            }
        }
        return area%MOD;
    }
};

int main(){

return 0;
}