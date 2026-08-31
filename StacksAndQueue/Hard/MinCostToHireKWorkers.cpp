#include<bits/stdc++.h>
using namespace std;

class Solution1{
    using vint=vector<int>;
        public: 
    double mincostToHireWorkers(vint &quality,vint &wage,int k) {
        int n=wage.size();
        double mini=1e12;
        for(int first=0;first<n;first++){
            double ratio=1.0*wage[first]/quality[first];
            priority_queue<double> pq;
            for(int worker=0;worker<n;worker++){
                double allotedWage=ratio*quality[worker];
                if(allotedWage>=wage[worker]){
                    if(pq.size()<k) pq.push(allotedWage);
                    else if(allotedWage<pq.top()){
                        pq.pop();
                        pq.push(allotedWage);
                    }
                }
            }
            if(pq.size()==k){
                double cost=0;
                while(!pq.empty()){
                    double w=pq.top(); pq.pop();
                    cost+=w;
                }
                mini=min(mini,cost);
            }
        }
        return mini;
    }
};

class Solution2 {
    // optimal
    using vint=vector<int>;
    using pdi=pair<double,int>;
    using vpdi=vector<pdi>;
        public:
    double mincostToHireWorkers(vint &quality,vint &wage,int k) {
        int n=wage.size();
        vpdi minimumWagePerQuality;
        for(int i=0;i<n;i++){
            int minWage=wage[i];
            minimumWagePerQuality.push_back({1.0*minWage/quality[i],i});
        }
        sort(minimumWagePerQuality.begin(),minimumWagePerQuality.end());
        priority_queue<int> pq;
        int qualitySum=0;
        double minCost=1e12;
        for(int firstPerson=0;firstPerson<n;firstPerson++){
            double ratio=minimumWagePerQuality[firstPerson].first;
            int idx=minimumWagePerQuality[firstPerson].second;
            int currQuality=quality[idx], minWage=wage[idx];
            pq.push(currQuality);
            if(pq.size()>k){
                int maxQuality=pq.top(); pq.pop();
                qualitySum-=maxQuality;
            }
            if(pq.size()==k){
                double cost=minWage+ratio*qualitySum;
                minCost=min(minCost,cost);
            }
            qualitySum+=currQuality;
        }
        return minCost;
    }
};

int main(){

return 0;
}