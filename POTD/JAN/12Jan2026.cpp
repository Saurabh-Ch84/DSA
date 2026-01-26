#include<iostream>
#include<vector>
#include<map>
using namespace std;


using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        map<int,int> maxMap;
        int left=0, right=0, n=arr.size(), winSize=0;
        vi result;
        while(right<n){
            int curr=arr[right];
            maxMap[curr]++;
            winSize++;
            if(winSize==k){
                auto maxEntry=*maxMap.rbegin();
                int maxi=maxEntry.first;
                result.push_back(maxi);
                int prev=arr[left];
                maxMap[prev]--;
                winSize--;
                left++;
                if(!maxMap[prev])
                    maxMap.erase(prev);
            }
            right++;
        }
        
        return result;
    }
};


class Solution {
    int minTimeToVisitQFromP(vi &p,vi &q){
        // Chebysev Distance
        return max(abs(p[0]-q[0]),abs(p[1]-q[1]));
    }
public:
    int minTimeToVisitAllPoints(vvi & points) {
        int n=points.size(), totalTime=0;
        for(int i=0;i<n-1;i++){
            int time=minTimeToVisitQFromP(points[i], points[i+1]);
            totalTime+=time;
        }
        return totalTime;
    }   
};

int main(){

return 0;
}