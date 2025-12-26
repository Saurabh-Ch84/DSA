#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<climits>

using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

using vi = vector<int> ;
using vvi = vector<vi> ;

class Solution {
public:
    vi smallestRange(vvi & nums) {
        int n=nums.size();
        priority_queue<vi,vvi,greater<vi>> pq;
        int largest=INT_MIN;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],0,i});
            largest=max(largest,nums[i][0]);
        }

        int spread=INT_MAX;       
        int mini=INT_MAX, maxi=INT_MIN;
        while(true){
            vi smallest=pq.top();
            int currSpread=largest-smallest[0];
            if(currSpread<spread){
                spread=currSpread;
                mini=smallest[0];
                maxi=largest;
            }
            int sJ=smallest[1], sI=smallest[2];
            int bound=nums[sI].size();
            if(sJ+1<bound){
                pq.pop();
                sJ++;
                int newVal=nums[sI][sJ];
                largest=max(largest,newVal);
                pq.push({newVal,sJ,sI});
            }
            else break;
        }

        return {mini,maxi};
    }
};

class Solution {
public:
    vi smallestRange(vvi & nums) {
        int n=nums.size();
        set<vi> rangeSet;
        for(int i=0;i<n;i++){
            rangeSet.insert({nums[i][0],0,i});
        }
        
        int spread=INT_MAX;       
        int mini=INT_MAX, maxi=INT_MIN;
        while(true){
            vi smallest=*rangeSet.begin();
            vi largest=*rangeSet.rbegin();
            int currSpread=largest[0]-smallest[0];
            if(currSpread<spread){
                spread=currSpread;
                mini=smallest[0];
                maxi=largest[0];
            }
            int sJ=smallest[1], sI=smallest[2];
            int bound=nums[sI].size();
            if(sJ+1<bound){
                rangeSet.erase(smallest);
                sJ++;
                int newVal=nums[sI][sJ];
                rangeSet.insert({newVal,sJ,sI});
            }
            else break;
        }

        return {mini,maxi};
    }
};

int main(){

return 0;
}