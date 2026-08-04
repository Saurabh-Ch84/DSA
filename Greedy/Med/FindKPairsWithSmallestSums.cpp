#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class SolutionBetter {
public:
    vvi kSmallestPairs(vi & nums1, vi &nums2, int k) {
        int n=nums1.size(), m=nums2.size(), i=0, j=0;

        vvi result;
        priority_queue<vi,vvi,greater<vi>> pq;
        pq.push({nums1[0]+nums2[0],0,0});
        set<pair<int,int>> hashSet;

        while(result.size()<k && !pq.empty()){
            vi entry=pq.top(); pq.pop();
            int i=entry[1], j=entry[2];
            result.push_back({nums1[i],nums2[j]});
            if(i+1<n && !hashSet.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                hashSet.insert({i+1,j});
            }
            if(j+1<m && !hashSet.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                hashSet.insert({i,j+1});
            }
        }
    
        return result;
    }
    
};

using vi = vector<int>;
using vvi = vector<vi>;

class SolutionBruteForce {
public:
    vvi kSmallestPairs(vi & nums1, vi &nums2, int k) {
        priority_queue<vi> pq;
        int n1=nums1.size(), n2=nums2.size();

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)
                    pq.push({sum,nums1[i],nums2[j]});
                else if(pq.top()[0]>sum){
                    pq.pop();
                    pq.push({sum,nums1[i],nums2[j]});
                }
                else break;
            }
        }
        
        vvi result(k);
        while(k-- && !pq.empty()){
            vi pair=pq.top(); pq.pop();
        	result[k]={pair[1],pair[2]};
        }
        return result;
    }
};

class SolutionOptimized {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    vvint kSmallestPairs(vint &nums1,vint &nums2,int k) {
        int n1=nums1.size(), n2=nums2.size();
        priority_queue<vint,vvint,greater<vint>>  pq;
        for(int i=0;i<n1;i++)
            pq.push({nums1[i]+nums2[0],i,0});
        vvint res;
        while(!pq.empty() && res.size()<k){
            vint entry=pq.top(); pq.pop();
            int i=entry[1], j=entry[2];
            res.push_back({nums1[i],nums2[j]});
            if(j<n2-1) pq.push({nums1[i]+nums2[j+1],i,j+1});
        }
        return res;
    }
};

int main(){

return 0;
}