#include<iostream>
#include<vector>
using namespace std;

class Solution {
    static bool comp(const pair<int,int> &a, const pair<int,int> &b){
        return a.second<b.second;
    }
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> interval;
        int n=start.size();
        for(int i=0;i<n;i++){
            interval.push_back({start[i],end[i]});
        }
        sort(interval.begin(),interval.end(),comp);
        int meetingCount=0,freeTime=0;
        for(pair<int,int> &p:interval){
            if(!meetingCount || p.first>freeTime){
                meetingCount++;
                freeTime=p.second;
            }
        }
        return meetingCount;
    }
};

int main(){

return 0;
}