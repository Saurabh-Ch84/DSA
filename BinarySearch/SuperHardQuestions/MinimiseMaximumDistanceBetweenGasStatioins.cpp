#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

//binarySearch Approach
class Solution1 {
    bool check(vector<int>&stationArr,double mid,int k,int n){
        double maxFeasibleDistance=mid;
        int stations=0;
        for(int i=1;i<n;i++){
            double distance=stationArr[i]-stationArr[i-1];
            if(distance>maxFeasibleDistance)
            {
                int noOfStation=ceil(distance/maxFeasibleDistance)-1;
                stations+=noOfStation;
            }
            if(stations>k) return false;
        }
        return true;
    }
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double low=0.0,high=0.0;
        int n=stations.size();
        for(int i=1;i<n;i++)
            high=max(high,(double)stations[i]-stations[i-1]);
        double precision=1e-6;//Good Enough for GFG.
        while(high-low>precision)
        {
            double mid=(high+low)/2.0;
            bool response=check(stations,mid,k,n);
            if(response) high=mid;
            else low=mid;
        }
        return high;
    }
};

//Using Priority Queue
class Solution2 {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        vector<int> sectionArr(n-1,0);
        priority_queue<pair<double,int>,vector<pair<double,int>>> pq;
        
        for(int i=0;i<n-1;i++){
            double gap=stations[i+1]-stations[i];
            pq.push({gap,i});
        }
        for(int station=0;station<k;station++){
            int section=pq.top().second;
            pq.pop();
            double gap=stations[section+1]-stations[section];
            sectionArr[section]++;
            double newSectionLength=(gap/(double)(sectionArr[section]+1));
            pq.push({newSectionLength,section});
        }
        double minMax=pq.top().first;
        return minMax;
    }
};

//Linear Search approach
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++) {
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}


int main(){

return 0;
}