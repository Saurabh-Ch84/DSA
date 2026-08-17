#include<bits/stdc++.h>
using namespace std;

class Solution {
    // we are using set instead of priority_queue because we need to delete an element from the middle of the data structure,  
    // which is not possible in priority_queue.
    using pii=pair<int,int>;
    class MedianFinder{
        set<pii,greater<pii>> maxSet;
        set<pii> minSet;
        void balance(){
            // do not subtract size of maxSet and minSet, like maxSet.size()-minSet.size()>1
            // because they return unsigned int, so it will always be >=0, so we need to use maxSet.size()>minSet.size()+1.
            while(!maxSet.empty() && maxSet.size()>minSet.size()+1){
                pair<int,int> maxInLeft=*maxSet.begin(); 
                maxSet.erase(maxInLeft);
                minSet.insert(maxInLeft);
            }
            while(!minSet.empty() && minSet.size()>maxSet.size()){
                pair<int,int> minInRight=*minSet.begin(); 
                minSet.erase(minInRight);
                maxSet.insert(minInRight);
            }
        }
            public:
        void addNum(int num,int idx){
            if(maxSet.empty() || num < maxSet.begin()->first)
                maxSet.insert({num,idx});
            else minSet.insert({num,idx});
            balance();
        }
        void deleteNum(int num,int idx){
            if(maxSet.count({num,idx})) maxSet.erase({num,idx});
            else minSet.erase({num,idx});
            // no need to call balance here since it will be called in the next addNum call, 
            // and we are always calling deleteNum before addNum in the main function.
        }
        double getMedian(){
            if(maxSet.size()>minSet.size()) return 1.0*maxSet.begin()->first;
            return (1.0*maxSet.begin()->first+1.0*minSet.begin()->first)/2;
        }
    };
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double> res(n-k+1);
        MedianFinder mf;
        for(int i=0;i<n;i++){
            // shrink the window size to k, by deleting the element which is going out of the window
            if(i>=k) mf.deleteNum(nums[i-k],i-k);
            // adding the new element which is coming into the window.
            mf.addNum(nums[i],i);
            // if the window size is k, then we can calculate the median and store it in the result vector.
            if(i-k+1>=0) res[i-k+1]=mf.getMedian();
        }
        return res;
    }
};

int main(){

return 0;
}